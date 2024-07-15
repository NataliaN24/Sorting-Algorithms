#include<iostream>

int partition(int arr[], int low, int high) {//rearranges the elements such that all elements less than or equal 
                                             //to the pivot are to the left, and elements greater than the pivot are to the right.
    int pivot = arr[high];
    int i = low;
    for (int j = low; j < high; j++) {
        if (arr[j] <= pivot) {
            std::swap(arr[i],arr[ j]);
            i++;

        }
    }
    std::swap(arr[i], arr[high]);
    return i;   //It returns the index of the pivot after partitioning.
}


void quickSort(int arr[],int low,int high) {
    if (low < high) {
        int pi = partition(arr, low, high);//pivot index
        quickSort(arr, low, pi - 1);   //it recursively sorts the sub-arrays to the left and right of the pivot.
        quickSort(arr, pi + 1, high);
    }

}


int main() {
    int arr[] = { 5, 4, 1, 9, 3, 7 };
    int n = sizeof(arr) / sizeof(arr[0]);
    quickSort(arr, 0, n - 1); //size-1 for lhs->5

    for (int i = 0; i < n; i++) {
        std::cout << arr[i] << " ";
    }

    return 0;
}

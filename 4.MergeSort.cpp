#include <iostream>

void merge(int arr[], int start, int mid, int end) {  // (arr,0,2,5)
    int i = 0;
    int j = 0;
    int k = start;

    int n1 = mid - start + 1;  //2-0+1=3 ->element=9
    int n2 = end - mid;    //5-2=3  ->element=9

    int* left = new int[n1];
    int* right = new int[n2];

    for (i = 0; i < n1; i++) {   //we place in a separate array the elements of the first divided array
        left[i] = arr[start + i];
    }
    for (j = 0; j < n2; j++) {
        right[j] = arr[mid + 1 + j];
    }

    i = 0;
    j = 0;

    while (i < n1 && j < n2) {
        if (left[i] <= right[j]) {
            arr[k] = left[i];
            i++;
        }
        else {
            arr[k] = right[j];
            j++;
        }
        k++;
    }

    while (i < n1) {
        arr[k] = left[i];
        i++;
        k++;
    }
    while (j < n2) {
        arr[k] = right[j];
        j++;
        k++;
    }

    delete[] left;
    delete[] right;
}

void mergeSort(int arr[], int lhs, int rhs) {
    if (lhs < rhs) {
        int medium = lhs + (rhs - lhs) / 2;   //0+5/2=2  if it was just lhs+rhs it could lead to integer truncation
        mergeSort(arr, lhs, medium);    // (arr,0,2)
        mergeSort(arr, medium + 1, rhs);    //(arr,3,5)
        merge(arr, lhs, medium, rhs);      // (arr,0,2,5)
    }
}

int main() {
    int arr[] = { 5, 4, 1, 9, 3, 7 };
    int n = sizeof(arr) / sizeof(arr[0]);
    mergeSort(arr, 0, n - 1); //size-1 for lhs->5

    for (int i = 0; i < n; i++) {
        std::cout << arr[i] << " ";
    }

    return 0;
}

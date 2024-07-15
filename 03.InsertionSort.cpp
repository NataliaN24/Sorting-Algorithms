#include<iostream>

void insertionSort(int* arr, int size) {
    for (int i = 1; i < size; i++) {
        int key = arr[i];
        int j = i - 1;
        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j = j - 1;
        }
        arr[j + 1] = key;
    }
}

int main() {
    int arr[] = { 5,4,1,9,3,7 };
   insertionSort(arr, 6);
    for (int i = 0; i < 6; i++) {
        std::cout << arr[i] << " ";
    }
}

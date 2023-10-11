#include<iostream>

void bubbleSort(int arr[], int size) {
    for (int i = 0; i < size - 1; i++) {
        for (int j = 0; j < size - i - 1; j++) {  // n-i-1 is done because after each pass of the outer loop,the largest element "bubbles up"to the end of array,so we don't have to compare it again.
            if (arr[j] > arr[j + 1]) {
                std::swap(arr[j], arr[j + 1]);
            }
        }
    }
}

int main() {
    int arr[] = { 5,4,1,9,3,7 };
    bubbleSort(arr, 6);
    for (int i = 0; i < 6; i++) {
        std::cout << arr[i] << " ";
    }
}

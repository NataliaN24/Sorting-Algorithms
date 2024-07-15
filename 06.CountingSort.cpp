#include<iostream>

//This code is better -------------------------------------------------------------------------------------------------------------------------------------------
void countingSort(char arr[], int n) {
    char* output = new char[n]; // Create an output array to store the sorted characters.

    // Initialize the count array with zeros.
    int count[256] = { 0 };

    // Count the occurrences of each character.
    for (int i = 0; i < n; i++) {
        count[arr[i]]++;
    }

    // Modify the count array to store the correct positions of characters in the output array.
    for (int i = 1; i < 256; i++) {
        count[i] += count[i - 1];
    }

    // Build the output array based on the count array.
    for (int i = n - 1; i >= 0; i--) {
        output[count[arr[i]] - 1] = arr[i];
        count[arr[i]]--;
    }

    // Copy the sorted characters from the output array back to the original array.
    for (int i = 0; i < n; i++) {
        arr[i] = output[i];
    }
    delete[]output;
}

//the code of lectures ------------------------------------------------------------------------------------------------------------------------------------------
void countingSort(char arr[], int n) {
    char* arr_copy = new char[n];

    for (int i = 0; i < n; ++i) {
        arr_copy[i] = arr[i];
    }
    
  int count[256] = { 0 };

    for (int i = 0; i < n; ++i) {
        count[arr[i]] = count[arr[i]] + 1;
    }
    for (int i = 1; i <= 255; ++i) {
        count[i] += count[i - 1];
    }
    
    for (int i = n - 1; i >= 0; i--) {
        arr_copy[count[arr[i]] - 1] = arr[i];
        count[arr[i]] = count[arr[i]] - 1;
    }
    for (int i = 0; i < n; i++) {
        arr[i] = arr_copy[i];
    }
    delete[]arr_copy;
   
}

//for int arr[]---------------------------------------------------------------------------------------------------------------------------------------------------
void counting_sort(int* arr, size_t arrLength) {
	int* arr_copy=new int[arrLength];

	int max = arr[0];
	for (int i = 0; i < arrLength; ++i) {
		if (max < arr[i]) {
			max = arr[i];
		}
		arr_copy[i] = arr[i];
	}

	int *count=new int[max + 1];
	for (int i = 0; i < max + 1; ++i) {
		count[i] = 0;
	}

	for (int i = 0; i < arrLength; ++i) {
		count[arr[i]]++;
	}

	for (int i = 1; i <= max; ++i) {
		count[i] += count[i - 1];
	}

	for (int i = arrLength - 1; i >= 0; --i) {
		arr[count[arr_copy[i]] - 1] = arr_copy[i];
		count[arr_copy[i]] = count[arr_copy[i]] - 1;
	}
}



int main() {
    char arr[] = { 'b', 'a', 'd', 'c', 'a', 'b' };
    int n = sizeof(arr) / sizeof(arr[0]);

    countingSort(arr, n);

    for (int i = 0; i < n; i++) {
        std::cout << arr[i] << " ";
    }

    return 0;
}

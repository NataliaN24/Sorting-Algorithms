#include <iostream>

template<class t>
void merge(t*arr1,int length1,t*arr2,int length2) {

	t* result = new t[length1 + length2];
	int cursor1 = 0; int cursor2 = 0; int rescursor = 0;

	while (cursor1 < length1 && cursor2 < length2) {
		if (arr1[cursor1] < arr2[cursor2]) {
			result[rescursor++] = arr1[cursor1++];
		}
		else {
			result[rescursor++] = arr2[cursor2++];
		}
	}

	while (cursor1<length1)
	{
		result[rescursor++] = arr1[cursor1++];
	}
	while (cursor2 < length2) {
		result[rescursor++] = arr2[cursor2++];
	}
	int finalLen = length1 + length2;
	for (int i = 0; i < finalLen; i++) {
		arr1[i] = result[i];
	}
	delete[]result;
}

template<class t>
void mergeSort(t*arr,int len) {
	
	if (len <= 1) { 
		return;
	}
	int mid = len / 2;
	mergeSort(arr, mid);
	mergeSort(arr+mid, len - mid);

	merge<t>(arr, mid, arr + mid, len - mid);

}

int main() {
    int arr[] = { 5, 4, 1, 9, 3, 7 };
    int n = sizeof(arr) / sizeof(arr[0]);
    mergeSort(arr, n); 

    for (int i = 0; i < n; i++) {
        std::cout << arr[i] << " ";
    }

    return 0;
}

#include<iostream>
using namespace std
int binarySearch(int* arr, int left, int right, int x)
{
	while (left <= right) 
	{
		int mid = left + (right - left) / 2;
    
		if (arr[mid] == x)
		{
			return mid;
		}
		else if (arr[mid] < x) 
		{
			left = mid + 1;
		}
		else
		{
			right = mid - 1;
		}
	}
	return -1;
}

int main()
{
	int n;
	cin >> n;
	int* arr = new int[n];
	for (int i = 0; i < n; i++)
    {
		cin >> arr[i];
	}
	std::sort(arr, arr + n);
	int x;
	cin >> x;

	cout<<"The element is found at index:"<< binarySearch(arr, 0, n - 1, x);
}

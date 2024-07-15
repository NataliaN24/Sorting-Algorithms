#include <vector>
#include <iostream>
#include<algorithm>
using namespace std;

int TernarySearch(const vector<int>& arr, int left, int right, int x)
{
	if (right >= left)
	{
		int mid1 = left + (right - left) / 3;
		int mid2 = right - (right - left) / 3;

		if (arr[mid1] == x) 
		{
			return mid1;
		}
		if (arr[mid2] == x)
		{
			return mid2;
		}
		if (x < arr[mid1]) 
		{
			return TernarySearch(arr, left, mid1 - 1, x);
		}
		else if (x > arr[mid2])
		{
			return TernarySearch(arr, mid2 + 1, right, x);
		}
		else 
		{
			return TernarySearch(arr, mid1 + 1, mid2 - 1, x);
		}
	}
	return -1;
}

int main()
{
	int n;
	cin >> n;
	vector<int>arr(n);
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}
	
	int x;
	cin >> x;

	cout << "Element is found at index:" << TernarySearch(arr, 0, n - 1, x);

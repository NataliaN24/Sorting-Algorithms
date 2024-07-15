#include <vector>
#include <iostream>
using namespace std;

int binarySearch(const vector<int>&arr, int left, int right, int x)
{
	if (right >= left)
  {
		int mid = left + (right - left) / 2;
		if (arr[mid] == x)
    {
			return mid;
		}
		if (arr[mid] > x)
    {
			return binarySearch(arr, left, mid - 1, x);
		}
		else
    {
			return binarySearch(arr, mid + 1, right, x);
		}
	}
	return -1;
}

int main() 
{
	int n;
	cin >> n;
	vector<int>arr(n);
	for (int i = 0; i < n; i++)
    {
		cin >> arr[i];
	}
	std::sort(arr.begin(), arr.end());
	int x;
	cin >> x;
	cout<<"The element is found at index:"<< binarySearch(arr, 0, n - 1, x);
}

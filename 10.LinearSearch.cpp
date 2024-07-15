#include<iostream>
using namespace std;

bool LinearSearch(const vector<int>&arr,  int x)
{
	for (int i = 0; i < arr.size(); i++)
	{
		if (arr[i] == x) 
		{
			return true;
		}
	}
  return false;
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
	int x;
	cin >> x;

	cout<< LinearSearch(arr, x);
}

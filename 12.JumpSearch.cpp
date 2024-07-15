#include <vector>
#include <iostream>
#include<algorithm>
using namespace std;

int JumpSearch(const vector<int>& arr, int x) {
    int len = arr.size();
    int jump = sqrt(len); 
    int start = 0;
    int end = start + jump;

    while (end < len && arr[end] <= x)
    {
        start = end; 
        end += jump;

        if (end > len - 1)
        {
            end = len;
        }
    }

    for (int i = start; i < end; i++) 
    {
        if (arr[i] == x)
        {
            return i;
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

	cout << "Element is found at index:" << JumpSearch(arr, x);
}

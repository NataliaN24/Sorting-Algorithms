#include <iostream>
#include <vector>
#include <limits>
#include<cmath>
#include<algorithm>

template <typename T>
void counting_sort(std::vector<T>& arr) {
	
	T max_val = *std::max_element(arr.begin(), arr.end());
	T min_val = *std::min_element(arr.begin(), arr.end());

	T range = max_val - min_val + 1;
	std::vector<int> count(range, 0);

	for (size_t i=0;i<arr.size();++i) {
		count[arr[i] - min_val]++;
	}
	std::vector<T> output(arr.size());

	for (size_t i = 1; i < count.size(); i++) {
		count[i] += count[i - 1];
	}
	for (int i = arr.size() - 1; i >= 0; i--) {
		output[count[arr[i] - min_val] - 1] = arr[i];
		count[arr[i] - min_val]--;
	}

	arr = output;
}

int main() {
	std::vector<int> int_arr = { 10, 7, 5, 3, 1, 0, 3, 6, 8, 9 };
	counting_sort(int_arr);
	for (const int& element : int_arr) {
		std::cout << element << " ";
	}
	std::cout << std::endl;

	std::vector<double> double_arr = { 10.5, 7.3, 5.1, 3.8, 1.6, 0.4, 3.5, 6.7, 8.9, 9.1 };
	counting_sort(double_arr);
	for (const double& element : double_arr) {
		std::cout << element << " ";
	}
	std::cout << std::endl;

	std::vector<char> char_arr = { 'f','d', 'b', 'c', 'a', 'e' };
	counting_sort(char_arr);
	for (const char& element : char_arr) {
		std::cout << element << " ";
	}
	std::cout << std::endl;

	return 0;
}

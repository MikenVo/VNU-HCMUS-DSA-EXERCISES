// Problem: Print out the sum of a given array using only Recursion

#include <iostream>
using namespace std;

int addArr(int arr[], int n, int& index) {
	if (index == n) {
		return arr[index];
	}
	else {
		int store = arr[index]; index++;
		return store + addArr(arr, n, index);
	}
}

int main() {
	int n; cin >> n;
	int m;
	int* arr = new int[n];
	for (int i = 0; i < n; i++) {
		cin >> m;
		arr[i] = m;
	}

	int index = 0;
	cout << "Result: " << addArr(arr, n, index) << endl;

	return 0;
}
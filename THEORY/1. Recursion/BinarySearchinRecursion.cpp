// Problem: Implement Binary search algorithm using recursion

#include <iostream>
using namespace std;

int search(int arr[], int left, int right, int target, int result) {
	int middle = (left + right) / 2;
	if (left > right) {
		return result;
	}

	if (arr[middle] == target) {
		return middle;
	}

	if (arr[middle] < target) {
		return search(arr, middle + 1, right, target, result);
	}
	else {
		return search(arr, left, middle - 1, target, result);
	}
}

int main() {
	int n; cin >> n;
	int* arr = new int[n];
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}

	int target; cin >> target;

	int result = search(arr, 0, n - 1, target, -1);
	cout << result << endl;

	return 0;
}
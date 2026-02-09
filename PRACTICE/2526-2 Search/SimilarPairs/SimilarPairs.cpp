#include <iostream>
using namespace std;

// Bubble sort
void sorted(int arr[], int n) {
	bool swapped = false;
	for (int i = 0; i < n; i++) {
		swapped = false;
		for (int j = 0; j < n - i - 1; j++) {
			if (arr[j] > arr[j + 1]) {
				int temp = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = temp;
				swapped = true;
			}
		}

		if (!swapped) {
			break;
		}
	}
}

int main() {
	int testcases = 0; cin >> testcases;
	for (int attempt = 0; attempt < testcases; attempt++) {
		int n;
		cin >> n;			   // Input the length of the array
		int *arr = new int[n]; // Memory-allocated array

		for (int i = 0; i < n; i++) {
			cin >> arr[i];
		}

		int odd_num = 0; // We need to count the number of odd numbers
						 // If the number of odd numbers is even, we can output "Yes"
						 // Example [1, 2, 5, 6]
						 // - Even numbers: 2
						 // - Odd numbers: 2
						 // - Similar pairs: (1, 2)-(5, 6) or (1, 5)-(2, 6)
		for (int i = 0; i < n; i++) {
			if (arr[i] % 2 != 0) {
				odd_num++;
			}
			else {
				continue;
			}
		}

		bool HasSimilarPairs = true;
		if (odd_num % 2 == 0) {
			cout << "Yes" << endl;
		}
		else {
			// The number of odd numbers is odd, we need to check if there is a pair that satisfies the difference is 1
			// Example: [1, 12, 3, 10, 5, 8]
			// - Odd numbers: 3 (1, 3, 5)
			// - Even numbers: 3 (8, 10, 12)
			// - Similar pairs: (1, 3)-(12, 10)- 5, 8 is left over. (1, 5)-(12, 8)-10, 3 is left over
			
			// Example 2: [1, 6, 3, 10, 5, 8]
			// - Odd numbers: 3 (1, 3, 5)
			// - Even numbers: 3 (6, 8, 10)
			// - Similar pairs: (1, 3)-(5, 6)-(8, 10)
			sorted(arr, n); // Sort the array to find the target pair (the difference of two numbers == 1) quick
			for (int i = 0; i < n - 1; i++) {
				for (int j = 1; j < n; j++) {
					if (abs(arr[i] - arr[j]) == 1) { // If we find it, immediately print out "Yes"
						cout << "Yes" << endl;
						HasSimilarPairs = true;
						break;
					}
					else {
						HasSimilarPairs = false; // If we haven't found it, search through the array
					}
				}

				if (HasSimilarPairs) {
					break;
				}
			}

			if (!HasSimilarPairs) { // If there is no such pair in the array, print out "No"
				cout << "No" << endl;
			}
		}
	}

	return 0;
}
#include <iostream>
using namespace std;

bool isSimilar(int firstnumber, int secondnumber) {
	int remainder1 = firstnumber % 2, remainder2 = secondnumber % 2;
	if ((abs(firstnumber - secondnumber) == 1) || (remainder1 == remainder2)) {
		return true;
	}
	return false;
}

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
	int testcases; cin >> testcases;
	int eachtest;
	for (int k = 0; k < testcases; k++) {
		bool HasSimilar = false;

		cin >> eachtest;
		if (eachtest % 2 != 0) {
			return 1;
		}

		int* test = new int[eachtest];
		for (int i = 0; i < eachtest; i++) {
			cin >> test[i];
		}

		sorted(test, eachtest);

		int checkpair = 1;

		for (int i = 0; i < eachtest - 1; i += 2) {
			for (int j = checkpair; j < eachtest; j++) {
				if (isSimilar(test[i], test[j])) {
					HasSimilar = true;
					break;
				}
				else {
					HasSimilar = false;
				}
			}

			if (!HasSimilar) {
				cout << "No" << endl;
				break;
			}
			else {
				checkpair += 2;
			}
		}

		if (HasSimilar) {
			cout << "Yes" << endl;
		}
	}

	return 0;
}
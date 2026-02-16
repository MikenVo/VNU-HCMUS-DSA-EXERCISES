// Read README.md in https://github.com/MikenVo/VNU-HCMUS-DSA-EXERCISES/tree/main/PRACTICE/2526-2%20Search/BinarySearch to know the problem

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// Use binary search
int binarySearchNearest(const vector<int>& a, int n, int x) {
	// Initialization
	int left = 0, right = n - 1, middle = (left + right) / 2;

	// Stop when the algorithm finds two "closest" number
	// Input: 5 1
	//		  1 5 3 22 23
	//		  24
	//
	// n = 5, q = 1
	// a = [1, 5, 3, 22, 23]
	// x (target) = 24
	// left = 0, right = 4, middle = 2 (a[middle] = 3 < x)
	// - a[left] != x, a[right] != x, a[middle] != x
	// left = middle = 2, right = 4, middle = 3 (a[middle] = 22 < x)
	// - a[left] != x, a[right] != x, a[middle] != x
	// left = middle = 3, right = 4, middle = 3 (a[middle] = 22 < x)
	// - a[left] != x, a[right] != x, a[middle] != x
	while (abs(left - right) != 1) {
		if (a[middle] == x) {
			return a[middle];
		}
		else if (a[middle] < x) {
			left = middle;
			middle = (left + right) / 2;
		}
		else if (a[middle] > x) {
			right = middle;
			middle = (left + right) / 2;
		}
	}

	// We have found two elements which are close to the target (a[left] = 22, a[right] = 23)
	// We need to calculate the differences and compare them to find the closest element
	// To know which element is larger than the other, we need to compare the differences.
	// - The larger the difference, the smaller the value
	// - The smaller the difference, the larger the value
	int diff1 = abs(a[left] - x), diff2 = abs(a[right] - x); // diff1 = abs(22 - 24) = 2, diff2 = abs(23 - 24) = 1
	if (diff1 > diff2) {
		return a[right];
	}
	else if (diff1 < diff2) {
		return a[left];
	}
	else {
		if (a[left] > a[right]) {
			return a[left];
		}
		else if (a[left] < a[right]) {
			return a[right];
		}
	}

	return -1;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int n, q;
	cin >> n >> q;
	if (n <= 0)
		return 0;

	vector<int> vals(n);
	for (int i = 0; i < n; ++i)
	{
		cin >> vals[i];
	}

	sort(vals.begin(), vals.end());

	while (q--) {
		int x;
		cin >> x;
		int nearest = binarySearchNearest(vals, n, x);
		cout << nearest << endl;
	}

	return 0;
}

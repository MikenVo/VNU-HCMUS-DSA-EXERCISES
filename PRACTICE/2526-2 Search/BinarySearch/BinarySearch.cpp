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
	// left = 0, right = 4, middle = 2 (at 
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

	int diff1 = abs(a[left] - x), diff2 = abs(a[right] - x);
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

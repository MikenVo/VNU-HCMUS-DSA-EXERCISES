#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// Auxiliary functions here
void FindOccurrence(int& result, int n, vector<int>& vals) {
	result = vals[0]; int count = 1;
	int current = vals[0], curcount = 0;

	for (int i = 0; i < n; i++) {
		if (current == vals[i]) {
			curcount++;
		}
		else if (current != vals[i]) {
			if (count < curcount) {
				result = current;
				count = curcount;
			}
			else if (count == curcount) {
				if (result > current) {
					result = current;
				}
			}

			current = vals[i];
			curcount = 1;
		}
	}

}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int n;
	cin >> n;
	if (n <= 0)
		return 0;

	vector<int> vals(n);
	for (int i = 0; i < n; ++i)
	{
		cin >> vals[i];
	}

	sort(vals.begin(), vals.end());

	// TODO: find max occurrence
	int result = 0;

	FindOccurrence(result, n, vals);

	cout << result;
	return 0;
}

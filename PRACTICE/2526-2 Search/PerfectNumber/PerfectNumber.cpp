#include <iostream>
using namespace std;

int AddDigits(int num) {
	int temp = num, total = 0;
	for (int i = 0; temp > 0; i++) {
		total += (temp % 10);
		temp /= 10;
	}
	return total;
}

int main() {
	int start = 19, curstanding = 1;
	int target_standing; cin >> target_standing;

	while (curstanding != target_standing) {
		start += 9;
		if (AddDigits(start) == 10) {
			curstanding++;
		}
	}

	cout << start << endl;
	return 0;
}
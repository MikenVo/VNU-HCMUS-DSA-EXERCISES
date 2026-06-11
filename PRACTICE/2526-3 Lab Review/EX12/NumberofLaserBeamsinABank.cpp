#include <iostream>
#include <vector>
#include <string>
using namespace std;

int numberOfBeams(vector<string> &bank) {
    int total = 0;

    vector<int> nums;

    for (int i = 0; i < bank.size(); i++) {
        int totalinrow = 0;
        for (int j = 0; j < bank[i].size(); j++) {
            if (bank[i][j] == '1') {
                totalinrow++;
            }
        }

        if (totalinrow != 0) nums.push_back(totalinrow);
    }

    if (!nums.empty()) {
        for (int i = 0; i < nums.size() - 1; i++) {
            total += nums[i] * nums[i + 1];
        }
    }

    return total;
}

int main() {
    int num; cin >> num;
    string s;
    vector<string> bank;
    for (int i = 0; i < num; i++) {
        cin >> s;
        bank.push_back(s);
    }

    cout << numberOfBeams(bank) << endl;

    return 0;
}
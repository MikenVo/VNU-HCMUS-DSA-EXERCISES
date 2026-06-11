#include <iostream>
#include <string>
#include <cmath>
using namespace std;

int scoreOfString(string s) {
    int priorSum = 0;
    int total = 0;
    char priorChar = '\0';

    for (int i = 0; i < s.size(); i++) {
        // 3 cases
        // 1. The current element == The next element -> Skip
        // 2. The current element != The next element, but the next element == the prior element -> plus the prior sum
        // 3. The current element != The next element, but the next element != the prior element -> take the difference
        if (i == s.size() - 1) {
            break;
        }

        if (s[i] != s[i + 1] && s[i + 1] != priorChar) { // Case 3
            priorSum = abs(s[i] - s[i + 1]); // Take the difference
            total += priorSum; // Add the sum to the total
            priorChar = s[i]; // Set the current element as the prior element
        }
        else if (s[i] != s[i + 1] && s[i + 1] == priorChar) { // Case 2
            total += priorSum; // Plus the prior sum to the total
            priorChar = s[i]; // Set the current element as the prior element
        }
        else {
            continue;
        }
    }

    return total;
}

int main() {
    string s; cin >> s;
    cout << scoreOfString(s) << endl;
    return 0;
}

// Time complexity: O(N)
// Space complexity: O(1)
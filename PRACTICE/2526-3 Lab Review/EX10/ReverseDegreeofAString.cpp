#include <iostream>
#include <string>
using namespace std;

// Problem 1: Find a way to convert the ASCII number to non-reversed alphabet order
// - Convert the ASCII to non-reversed alphabet order
// - Example: a (97) -> a (1)
// - Solution: Take the difference between the ASCII number and 96
// a (97) - 96 = 1
// b (98) - 96 = 2
// c (99) - 96 = 3

// Problem 2: Find a way to reverse the order
// - From the "original" alphabet order, we convert it into the reversed alphabet order
// - Example: a (1) -> a (26)
// - Solution: x + 25 - (x - 1) * 2 with x is the non-reversed position of a character in the alphabet
// a (1 + 25 - 0*2 = 26)
// b (2 + 25 - 1*2 = 25)
// c (3 + 25 - 2*2 = 24)

int reverseDegree(string s) {
    int conversion = 0; // Store the convert number
    int total = 0; // Store the degree of the string
    for (int i = 0; i < s.size(); i++) {
        conversion = (s[i] - 96) + 25 - (s[i] - 96 - 1) * 2;
        total += conversion * (i + 1);
    }
    return total;
}

int main() {
    string s; cin >> s;
    cout << reverseDegree(s);
    return 0;
}

// Time complexity: O(n)
// Space complexity: O(1)

// Test cases
// Input: dsa
// Output: 117

// Input: fit
// Output: 78

// Input: hcmus
// Output: 173
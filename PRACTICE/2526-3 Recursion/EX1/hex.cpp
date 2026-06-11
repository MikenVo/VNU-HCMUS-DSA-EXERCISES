#include <iostream>
#include <string>
using namespace std;

// Base case:  x == 0, return the whole string
// Divide by 16, check the numbers and return the string
// THe prior string will push back the post string

// 11 & 16 = 11
// 11 / 16 = 0

string decimal2Hex(int x) {
    if (x == 0) return ""; // Base case
    string hex = "0123456789ABCDEF"; // A string for the number to map to a character in Hex
    int remainder = x % 16; // Convert the current number to Hex
    return decimal2Hex(x / 16) + hex[remainder];
}

int hex2Decimal(string s) {
    // The way to convert Hex to Dec is take every digit and multiply with 16 to the power of its position
    // Example: 1A
    // A = 10 => Dec = 10 * 16^0 = 10
    // 1 = 1 => Dec = 10 + 1 * 16^2 = 26
    // Dec = 26

    char lastChar = s.back(); // Take out the last digit in the string
    int lastVal;

    // Convert Hex to Dec
    if (lastChar >= '0' && lastChar <= '9') {
        lastVal = lastChar - '0';
    }
    else if (lastChar >= 'A' && lastChar <= 'F') {
        lastVal = lastChar - 'A' + 10;
    }
    else if (lastChar >= 'a' && lastChar <= 'f') { // Handle non-capitalized characters
        lastVal = lastChar - 'a' + 10;
    }

    if (s.length() == 1) return lastVal; // Base case

    // Create a new string that omits the last character
    string subStr = s.substr(0, s.length() - 1);

    // Do the operations
    return hex2Decimal(subStr) * 16 + lastVal;
}

int main() {
    int num;
    cout << "Input the Dec number: ";
    cin >> num;

    // Khắc phục kịch bản 1: Xử lý riêng số 0
    if (num == 0) {
        cout << "0" << endl;
    }
    else {
        cout << decimal2Hex(num) << endl;
    }

    // Khắc phục kịch bản 2: Xóa bộ đệm trước khi nhập tiếp chuỗi
    cin.ignore(1000, '\n');

    string s;
    cout << "Input the Hex number: ";
    cin >> s;
    cout << hex2Decimal(s) << endl;

    return 0;
}

// dec2Hex complexities:
// N is the number
// - Time complexity: O(log_16 N)
// - Space complexity: O(log_16 N)

// hex2Dec complexities:
// L is the length of the string
// - Time complexity: O(L^2)
// - Space complexity: O(L)

// Test cases:
// Input: 26 1A
// Output: 1A 26

// Input: 11 4B
// Output: B 75

// Input: 15 34B
// Output: F 843
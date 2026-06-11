#include <iostream>
using namespace std;

int gcd(int firstnumber, int secondnumber) {
    // Use Euclidean Algorithm to find the greatest common divisor
    int remainder = firstnumber % secondnumber;
    while (remainder != 0) {
        firstnumber = secondnumber;
        secondnumber = remainder;
        remainder = firstnumber % secondnumber;
    }

    return secondnumber;
}

int baseTotal(int base, int num) {
    // Convert the input from base 10 to other base
    int total = 0;
    while (num > 0) { // Divide the input with a certain number and sum them up
        total += num % base;
        num /= base;
    }

    // Example: 10 (base 10) -> 1010 (base 2)
    // - 10 / 2 = 5, 10 % 2 = 0
    // - 5 / 2 = 2, 5 % 2 = 1
    // - 2 / 2 = 1, 2 % 2 = 0
    // - 1 / 2 = 0, 1 % 2 = 1

    return total;
}

int main() {
    int num; cin >> num;
    int numerator = 0;
    int denomerator = num - 2; 
    // This is the number of conversion the input has to pass through
    // Example: 5
    // - We have to convert 5 from base 10 to base 2, 3, and 4 -> Denomerator = 3
    // Therefore, to find this number: (num - 1) - 2 + 1 = num - 2
    int GCD;

    for (int base = 2; base < num; base++) { // Sum all the converted numbers
        numerator += baseTotal(base, num);
    }

    GCD = gcd(numerator, denomerator);

    // Reduce the fraction
    cout << numerator / GCD << "/" << denomerator / GCD << endl;

    return 0;
}

// Time complexity: O(n log n)
// Space complexity: O(1)

// Test cases
// Input: 10
// Output: 3/1

// Input: 8
// Output: 8/3

// Input: 7
// Output: 3/1

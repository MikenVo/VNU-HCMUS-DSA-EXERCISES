// Problem: Given an array from 1 to n. Find sqrt(n).

#include <iostream>
using namespace std;

int main() {
    double n; cin >> n;
    double epsilon = 0.00000000000001;
    double left = 1.0, right = n;

    while (left < right) {
        double mid = left + (right - left) / 2.0;

        if (abs(mid * mid - n) <= epsilon) {
            cout << mid << endl;
            break;
        }
        else if (mid * mid > n) {
            right = mid - epsilon;
        }
        else {
            left = mid + epsilon;
        }
    }

    return 0;
}
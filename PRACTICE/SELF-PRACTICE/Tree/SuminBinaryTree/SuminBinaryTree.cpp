#include <iostream>
using namespace std;

int main() {
    // We take the current number and add it to the total first
    // Then calculate the prior number based on (2n) or (2n - 1) with n is the prior number
    // - If the current number is even, we use 2n to find the prior number
    // - If the current number is odd, we use 2n - 1 to find the prior number
    // Repeat until the current number hits 1
    
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t; cin >> t; // Input the number of test cases
    while(--t >= 0) {
        long long n; cin >> n; // Input a vertex number

        long long current = n;
        long long total = 0;

        while (current >= 1) {
            total += current; // Add the current number first
            if (current % 2 == 0) { // If the current number is even
                current = current / 2; // Get the new current number
            }
            else { // If the current number is odd
                current = (current - 1) / 2; // Get the new current number
            }
        }

        cout << total << endl;
    }

    return 0;
}
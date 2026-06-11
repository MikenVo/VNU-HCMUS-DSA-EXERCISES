#include <iostream>
using namespace std;

int main() {
    int n; cin >> n; // The number of elements
    long long d; cin >> d; // Common difference
    long long* arr = new long long[n]; // Sequence
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    long long steps = 0; // The minimum steps
    long long diff; // Calculate the "difference" between the current element with the minimum > a[i - 1]
    // Example: 1 3 3 2
    // - AFter loop 1: 1 3 5 2
    // - - 5 > 2 (The minimum number > 5: 6) -> diff = 6 - 2 = 4
    long long multiply;

    for (int i = 1; i < n; i++) { // Iterate each element in the array
        if (arr[i] <= arr[i - 1]) { // If the current element <= the prior element
            diff = arr[i - 1] - arr[i] + 1; // Calculate the difference
            steps += ((diff + d - 1) / d); // Calculate the steps to get the current element > the prior element 
            multiply = ((diff + d - 1) / d); // Store the current steps to use to update the current element
            arr[i] += multiply * d;
        }
    }

    cout << steps << endl;

    delete[] arr;
    return 0;
}

// Time complexity: O(n)
// Space complexity: O(n)

// Test cases
/* Input:
*  6 3
*  3 5 9 4 8 3
*/
// Output: 6

/* Input:
*  5 1
*  2 2 2 2 2
*/
// Output: 10

/* Input:
*  5 4
*  3 8 5 9 2
*/
// Output: 5
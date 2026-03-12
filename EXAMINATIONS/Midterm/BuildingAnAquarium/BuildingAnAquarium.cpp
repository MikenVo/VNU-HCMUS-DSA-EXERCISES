#include <iostream>
using namespace std;

bool is_sufficient(unsigned int heights[], unsigned int n, unsigned int x, unsigned int h) {
    int count = 0; // Initialize the count to track the amount of water
    for (int i = 0; i < n; i++) {
        if (heights[i] > h) continue; // If the current coral height is higher than the chosen height, skip

        count += h - heights[i]; // Add the amount of water

        if (count > x) return false; // If the amount of water is overflow, return false (the height is not satisfied)
    }
    return true; // The height is satisfied
}

int main() {
    int t; cin >> t; // Input the number of test cases
    for (int test = 0; test < t; test++) {
        unsigned int n; cin >> n; // Input the number of columns of the coral
        unsigned int x; cin >> x; // Input the maximum amount of water
        unsigned int* heights = new unsigned int[n]; // Initialize the array to record the corals' heights

        // Input array
        for (int height = 0; height < n; height++) {
            cin >> heights[height];
        }

        // Guess a height using Binary Search (the middle element between 1 and 1 000 000 000)
        // We check if that height is sufficient for the amount of water we got
        // - If the height is satisfied, we set the left pointer to mid + 1 (we want to push more to find the highest)
        // - If the height is not satisfied, we set the right pointer to the current height (we want to shrink the finding scope)
        // The algorithm stops when left > right, and print out the result

        unsigned int left = 1, right = 2000000000; // Initialize the lower bound and upper bound
        unsigned int result = 0; // Initialize the variable to save the result

        // Binary Search
        while (left <= right) {
            unsigned int mid = left + (right - left) / 2; // Calculate the middle of the lower and upper bound and use it as a height to check
            if (is_sufficient(heights, n, x, mid)) { // Check if the chosen height is satisfied
                result = mid; // If yes, save it temporarily
                left = mid + 1; // Move the lower bound up to find the maximum
            }
            else {
                right = mid - 1; // Move the upper bound down to shrink the finding scope
            }
        }

        cout << result << endl; // Print out the result

        delete[] heights;
    }

    return 0;
}
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// Algorithm:
// - Example: [1, 3, 5, 4, 2]
// 1. Find the break point in the increasing order from right to left.
// - Break point: 3
// - Explanation: From right to left, the first element that doesn't follow the increasing order is the break point.
// 2. Find the first element larger than the break point in the increasing order.
// - The first element larger than the break point: 4 (a[3])
// 3. Swap that first element with the break point: [1, 4, 5, 3, 2].
// 4. Reverse the order of the new increasing order: [1, 4, 2, 3, 5].

void nextPermutation(vector<int> &nums) {
    int n = nums.size();
    int i = n - 2;

    // Find the break point in the increasing order from right to left
    while (i >= 0 && nums[i] >= nums[i + 1]) {
        i--;
    }

    // Find the first element that is larger than the break point in the increasing order and swap with the break point
    if (i >= 0) {
        int j = n - 1;
        while (nums[j] <= nums[i]) {
            j--;
        }
        swap(nums[j], nums[i]);
    }

    // Reverse the new increasing order
    reverse(nums.begin() + i + 1, nums.end());
}

int main() {
    int n; cout << "Please input the number of elements: "; cin >> n;
    vector<int> nums(n);

    for (int i = 0; i < n; i++) {
        cout << "Input element " << i + 1 << ": "; cin >> nums[i];
    }

    nextPermutation(nums);

    cout << "[";
    for (int i = 0; i < n; i++) {
        cout << nums[i];
        if (i < n - 1) {
            cout << ", ";
        }
    }
    cout << "]";

    return 0;
}

// Time complexity: O(N)
// Space complexity: O(1)

// Test cases:
// Input: [1, 3, 5, 4, 2]
// Output: [1, 4, 2, 3, 5]

// Input: [3, 6, 4, 8]
// Output: [3, 6, 8, 4]

// Input: [7, 3, 5, 4]
// Output: [7, 4, 3, 5]
#include <iostream>
#include <vector>

using namespace std;

/**
 * Perform backtracking to generate all permutations of the input vector.
 * * vector<int> &nums: The original vector of numbers to permute.
 * vector<bool> &used: A boolean vector to keep track of elements currently in the permutation.
 * vector<int> &current: The vector storing the permutation currently being built.
 * vector<vector<int>> &list: The collection of all generated permutations.
 */
void backtrack(const vector<int> &nums, vector<bool> &used, vector<int> &current, vector<vector<int>> &list)
{
    // Base case: If the current permutation length equals the number of elements, a complete permutation is formed.
    if (current.size() == nums.size())
    {
        list.push_back(current);
        return;
    }

    // Iterate through all elements to build the permutation recursively.
    for (int i = 0; i < nums.size(); i++)
    {
        // Skip elements that are already included in the current permutation path.
        if (used[i] == true)
        {
            continue;
        }

        // Mark element as used and add it to the current path.
        used[i] = true;
        current.push_back(nums[i]);

        // Recurse to fill the next position.
        backtrack(nums, used, current, list);

        // Backtrack: remove the element and mark it as unused for other branches.
        current.pop_back();
        used[i] = false;
    }
}

/**
 * Initialize structures and trigger the backtracking process.
 */
vector<vector<int>> permute(vector<int> &nums)
{
    vector<bool> used(nums.size(), false);
    vector<int> current;
    vector<vector<int>> list;
    backtrack(nums, used, current, list);
    return list;
}

int main()
{
    int n;
    cout << "Input the number of elements: ";
    cin >> n;

    vector<int> nums;

    for (int i = 0; i < n; i++)
    {
        int m;
        cout << "Input element " << i + 1 << ": ";
        cin >> m;
        nums.push_back(m);
    }

    vector<vector<int>> list = permute(nums);

    cout << "[";
    for (int i = 0; i < list.size(); i++)
    {
        cout << "[";
        for (int j = 0; j < list[i].size(); j++)
        {
            cout << list[i][j];

            if (j < list[i].size() - 1)
            {
                cout << ", ";
            }
        }
        cout << "]";

        if (i < list.size() - 1)
        {
            cout << ",";
        }
    }
    cout << "]";

    return 0;
}

// Time Complexity: O(N * N!)
// Space Complexity: O(N)

// Test cases
// Input: [1, 2]
// Output: [[1, 2], [2, 1]]

// Input: [1, 2, 3]
// Output: [[1, 2, 3], [1, 3, 2], [2, 1, 3], [2, 3, 1], [3, 1, 2], [3, 2, 1]]

// Input: [5]
// Output: [[5]]
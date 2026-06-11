#include <iostream>
#include <unordered_map>
#include <vector>
#include <algorithm>
using namespace std;

vector<vector<int>> sortMatrix(vector<vector<int>>& grid) {
    int n = grid.size();
    unordered_map<int, vector<int>> diagonals;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            diagonals[i - j].push_back(grid[i][j]); // Map the element into the hash table
        }
    }

    for (auto &pair : diagonals) {
        int key = pair.first;
        if (key >= 0) { // If the element is on the main diagonal or the left lower side of the matrix
            sort(pair.second.begin(), pair.second.end(), greater<int>()); // Sort the elements in the decreasing order
        }
        else {  // If the element is on the right upper side of the matrix
            sort(pair.second.begin(), pair.second.end()); // Sort the elements in the increasing order
        }

        reverse(pair.second.begin(), pair.second.end());
        // Reverse the array in each key so that we can take out the first element much easily without moving other elements
        // - Example: [1, 9, 7] -> (Sorted) [9, 7, 1] -> (Reversed) [1, 7, 9] -> Pop the "first" element [1, 7]
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            int key = i - j;
            grid[i][j] = diagonals[key].back();
            // Take out the last element in the reversed order (the first element in the original order) and assign to the position
            diagonals[key].pop_back();
        }
    }

    return grid;
}

int main() {
    int m; cin >> m;

    vector<vector<int>> grid(m, vector<int>(m, 0));

    for (int i = 0; i < m; i++) {
        for (int j = 0; j < m; j++) {
            cin >> grid[i][j];
        }
    }

    cout << "----------------" << endl;

    vector<vector<int>> result = sortMatrix(grid);

    for (int i = 0; i < m; i++) {
        for (int j = 0; j < m; j++) {
            cout << result[i][j] << " ";
        }
        cout << "\n";
    }

    return 0;
}

// Time complexity: O(n^2 log n)
// Space complexity: O(n^2)
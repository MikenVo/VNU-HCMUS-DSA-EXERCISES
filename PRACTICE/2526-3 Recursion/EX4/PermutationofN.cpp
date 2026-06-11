#include <iostream>
#include <vector>
using namespace std;

void permutation(int N, vector<int>& current, vector<bool>& used) {
    if (current.size() == N) {
        cout << "[";
        for (int i = 0; i < N; i++) {
            if (i != N - 1) {
                cout << current[i] << ", ";
            }
            else {
                cout << current[i];
            }
        }
        cout << "]";
        return;
    }

    for (int i = 1; i <= N; i++) {
        if (!used[i]) { // Check if the number has been used yet
            // If the number hasn't been used
            used[i] = true;
            current.push_back(i); // Add the number to the current permutation

            permutation(N, current, used);

            current.pop_back();
            used[i] = false;
        }
    }
}

int main() {
    int N;
    cout << "Input: N = ";
    cin >> N;

    vector<int> current;
    vector<bool> used(N + 1, false);

    cout << "Output: [";
    permutation(N, current, used);
    cout << "]" << endl;

    return 0;
}

// Time complexity: O(N * N!)
// Space complexity: O(N)

// Test case:
// Input: N = 1
// Output: [[1]]

// Input: N = 2
// Output: [[1, 2], [2, 1]]

// Input: N = 4
/* Output: [
  [1,2,3,4],[1,2,4,3],[1,3,2,4],[1,3,4,2],[1,4,2,3],[1,4,3,2],
  [2,1,3,4],[2,1,4,3],[2,3,1,4],[2,3,4,1],[2,4,1,3],[2,4,3,1],
  [3,1,2,4],[3,1,4,2],[3,2,1,4],[3,2,4,1],[3,4,1,2],[3,4,3,1],
  [4,1,2,3],[4,1,3,2],[4,2,1,3],[4,2,3,1],[4,3,1,2],[4,3,2,1]
] */
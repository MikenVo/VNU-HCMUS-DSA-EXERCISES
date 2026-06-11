#include <iostream>
#include <vector>

using namespace std;

// Problem 1: Place the knight on the board
// We use a 1D array to track the movement of the knight.
// - The indices are the rows
// - The values are the columns
// To put a piece on the board, we run a loop to go through all the possible starts of the knight.
// - Inside that loop, we run a recursion to check of the possible moves of the knight.

// Problem 2: Move the knight
// There are 6 valid moves of the knight if it starts at cell (i, j):
// 1. (i + 2, j + 1)
// 2. (i + 2, j - 1)
// 3. (i + 1, j - 2)
// 4. (i - 1, j - 2)
// 5. (i - 2, j - 1)
// 6. (i - 2, j + 1)
// 7. (i - 1, j + 2)
// 8. (i + 1, j + 2)

// Problem 3: Check the validation
// - For a move to be considered valid, it must meet 2 requirements:
// 1. The move must be in the table.
// 2. The move must be only 1 in 8 valid moves.

// Problem 4: Get them together
// Base case: Stop when every cells is visited
// Operation: Check the validation of the move the knight can jump to.
// - If it is valid, set the cell in the board true and add the move into moves.

int dr[8] = {2, 2, 1, -1, -2, -2, -1, 1};
int dc[8] = {1, -1, -2, -2, -1, 1, 2, 2};

bool isValid(int row, int col, const vector<vector<int>>& board, int N) {
    if ((row >= N || row < 0) || (col < 0 || col >= N)) {
        return false;
    }

    if (board[row][col] == 1) {
        return false;
    }
    return true;
}

// int row, int col: Current cell the knight is standing
// int step: The total of steps the knight has moved
// vector<pair<int,int>> path: Store the moves that the knight has moved
// vector<vector<int>> board: To keep track the visited cell
// vector<vector<int>> result: To store the available results
// int N: The number of rows/cols
// bool solve: Keep track if the board is solved or not
void knightTour(int row, int col, int step, vector<vector<int>>& board, vector<pair<int,int>>& path, int N, bool& solve) {
    if (solve) return;
    
    // Add the move to the path first
    board[row][col] = 1;
    path.push_back({row, col});
    
    if (step == N * N) {
        // Print out if a path is found
        cout << "Knight's moves: ";
        for (int i = 0; i < path.size(); i++) {
            cout << "(" << path[i].first << ", " << path[i].second << ")";
            if (i < path.size() - 1) {
                cout << " -> ";
            }
        }
        solve = true;
        return;
    }
    else {
        // Iterate through 8 moves
        for (int i = 0; i < 8; i++) {
            int nextRow = row + dr[i];
            int nextCol = col + dc[i];
            if (isValid(nextRow, nextCol, board, N)) knightTour(nextRow, nextCol, step + 1, board, path, N, solve);
        }
    }

    // Backtrack
    board[row][col] = -1; // Set the failed move to -1
    path.pop_back(); // Remove the move from the path
}

int main() {
    int N; cout << "Please input N to generate a N x N board: "; cin >> N;
    vector<vector<int>> board(N, vector<int>(N, -1));
    vector<pair<int,int>> path;
    bool solve = false;

    int startRow, startCol; cout << "Please input the starting cell (Row first, Col second): "; cin >> startRow >> startCol;

    knightTour(startRow, startCol, 1, board, path, N, solve);

    if (!solve) {
        cout << "No available path!" << endl;
    }

    return 0;
}

// Time complexity: O(8^N^2)
// Space complexity: O(N^2)

// Test cases:
// Input: 1 0 0
// Output: (0, 0)

// Input: 3 0 0
// Output: No available path!

// Input: 5 0 0
// Output: Knight's moves: (0, 0) -> (2, 1) -> (4, 2) -> (3, 0) -> (1, 1) -> (0, 3) -> (2, 4) -> (4, 3) -> (3, 1) -> (1, 0) ->
//                         (0, 2) -> (1, 4) -> (3, 3) -> (4, 1) -> (2, 2) -> (3, 4) -> (1, 3) -> (0, 1) -> (2, 0) -> (1, 2) ->
//                         (0, 4) -> (2, 3) -> (4, 4) -> (3, 2) -> (4, 0)
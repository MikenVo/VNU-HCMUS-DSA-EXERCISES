#include <iostream>
#include <vector>

using namespace std;

// Problem 1: Placing pieces
// 1D array is used to track the cell that the queens capture
// Example: [1, 3, 0, 2]
// - Indices are the rows. Values are the columns
// - There are queens standing at cell (0, 1), (1, 3), (2, 0), (3, 2)

// Problem 2: Checking collisions

/*
*  1. Check the rows and columns
*  - When a piece is placed on one cell, we cannot place another piece on the column and row where it is standing
*  - To put a piece at cell (i, j), we need to check through the previous row to see if there is a piece standing on the same column
*  Example: board = [1, 3, 0, ] "I want to put a piece at cell (3, 3)."
*  - Check through the rows before 3.
*  - A piece is standing at (0, 1) (Good)
*  - A piece is standing at (1, 3) (Not good)
*  - A piece is standing at (2, 0) (Good)
*  - Therefore, we cannot put a piece at cell (3, 3) because there is a piece already occupying column 3 [cell (1, 3)].
*/

/*
*  2. Check the diagonals
*  - If the two pieces are on the same diagonal, the displacement of rows and columns is the same.
*    - Take (2, 3) and (4, 5) as an example, the cell (4, 5) is 2 rows down and 2 columns right.
*  Example: board = [1] "I want to put a piece at cell (3, 4)."
*  - abs(0 - 3) = 3, abs(1 - 4) = 3 => These two cells are on the same diagonal! We cannot put a piece here.
*  Example 2: board = [1] "I want to put a piece at cell (3, 5)."
*  - abs(0 - 3) = 3, abs(1 - 5) = 4 => These two cells are NOT on the same diagonal! We can put a piece here (Of course, after checking the row and column).
*/

// Problem 3: Get everything together into recursions

// Check the current cell is safe to put the piece
bool isSafe(const vector<int>& board, int row, int col) {
    for (int i = 0; i < row; i++) {
        if (board[i] == col || abs(i - row) == abs(board[i] - col)) { // Check if the diagonal and the column contain the cell is occupied or not
            return false;
        }
    }
    
    return true;
}

void NQueens(int row, vector<int>& board, vector<vector<int>>& result, int N) {
    if (row == N) { // If we have place N pieces on the N x N board, we get the result
        result.push_back(board);
        return;
    }

    for (int i = 0; i < N; i++) { // The loop go through each row in the board
        if (isSafe(board, row, i)) {
            board[row] = i;
            NQueens(row + 1, board, result, N);
        }
    }
}

int main() {
    int N; cout << "Please input the number of queens: "; cin >> N;
    vector<int> board(N);
    vector<vector<int>> result;

    NQueens(0, board, result, N);
    
    int counter = 0;

    cout << "The cells where the Queens are standing: ";
    for (int i = 0; i < N; i++) {
        if (i == N - 1) {
            cout << "(";
            cout << i << "; " << result[0][counter++];
            cout << ")";

            break;
        }

        cout << "(";
        cout << i << "; " << result[0][counter++];
        cout << "), ";
    }

    return 0;
}

// Time complexity: O(N! * N)
// Space complexity: O(N)

// Test cases
// Input: 4
// Output: [1, 3, 0, 2] [2, 0, 3, 1]

// Input: 8
// Output: [0, 4, 7, 5, 2, 6, 1, 3] [0, 5, 7, 2, 6, 3, 1, 4] [0, 6, 3, 5, 7, 1, 4, 2] [0, 6, 4, 7, 1, 3, 5, 2] [1, 3, 5, 7, 2, 0, 6, 4]
//         [1, 4, 6, 0, 2, 7, 5, 3] [1, 4, 6, 3, 0, 7, 5, 2] [1, 5, 0, 6, 3, 7, 2, 4] [1, 5, 7, 2, 0, 3, 6, 4] [1, 6, 2, 5, 7, 4, 0, 3]
//         [1, 6, 4, 7, 0, 3, 5, 2] [1, 7, 5, 0, 2, 4, 6, 3] [2, 0, 6, 4, 7, 1, 3, 5] [2, 4, 1, 7, 0, 6, 3, 5] [2, 4, 1, 7, 5, 3, 6, 0]
//         [2, 4, 6, 0, 3, 1, 7, 5] [2, 4, 7, 3, 0, 6, 1, 5] [2, 5, 1, 4, 7, 0, 6, 3] [2, 5, 1, 6, 0, 3, 7, 4] [2, 5, 1, 6, 4, 0, 7, 3]
//         [2, 5, 3, 0, 7, 4, 6, 1] [2, 5, 3, 1, 7, 4, 6, 0] [2, 5, 7, 0, 3, 6, 4, 1] [2, 5, 7, 0, 4, 6, 1, 3] [2, 5, 7, 1, 3, 0, 6, 4]
//         [2, 6, 1, 7, 4, 0, 3, 5] [2, 6, 1, 7, 5, 3, 0, 4] [2, 7, 3, 6, 0, 5, 1, 4] [3, 0, 4, 7, 1, 6, 2, 5] [3, 0, 4, 7, 5, 2, 6, 1]
//         [3, 1, 4, 7, 5, 0, 2, 6] [3, 1, 6, 2, 5, 7, 0, 4] [3, 1, 6, 2, 5, 7, 4, 0] [3, 1, 6, 4, 0, 7, 5, 2] [3, 1, 7, 4, 6, 0, 2, 5]
//         [3, 1, 7, 5, 0, 2, 4, 6] [3, 5, 0, 4, 1, 7, 2, 6] [3, 5, 7, 1, 6, 0, 2, 4] [3, 5, 7, 2, 0, 6, 4, 1] [3, 6, 0, 7, 4, 1, 5, 2]
//         [3, 6, 2, 7, 1, 4, 0, 5] [3, 6, 4, 1, 5, 0, 2, 7] [3, 6, 4, 2, 0, 5, 7, 1] [3, 7, 0, 2, 5, 1, 6, 4] [3, 7, 0, 4, 6, 1, 5, 2]
//         [3, 7, 4, 2, 0, 6, 1, 5] [4, 0, 3, 5, 7, 1, 6, 2] [4, 0, 7, 3, 1, 6, 2, 5] [4, 0, 7, 5, 2, 6, 1, 3] [4, 1, 3, 5, 7, 2, 0, 6]
//         [4, 1, 3, 6, 2, 7, 5, 0] [4, 1, 5, 0, 6, 3, 7, 2] [4, 1, 7, 0, 3, 6, 2, 5] [4, 2, 0, 5, 7, 1, 3, 6] [4, 2, 0, 6, 1, 7, 5, 3]
//         [4, 2, 7, 3, 6, 0, 5, 1] [4, 6, 0, 2, 7, 5, 3, 1] [4, 6, 0, 3, 1, 7, 5, 2] [4, 6, 1, 3, 7, 0, 2, 5] [4, 6, 1, 5, 2, 0, 3, 7]
//         [4, 6, 1, 5, 2, 0, 7, 3] [4, 6, 3, 0, 2, 7, 5, 1] [4, 7, 3, 0, 2, 5, 1, 6] [4, 7, 3, 0, 6, 1, 5, 2] [5, 0, 4, 1, 7, 2, 6, 3]
//         [5, 1, 6, 0, 2, 4, 7, 3] [5, 1, 6, 0, 3, 7, 4, 2] [5, 2, 0, 6, 4, 7, 1, 3] [5, 2, 0, 7, 3, 1, 6, 4] [5, 2, 0, 7, 4, 1, 3, 6]
//         [5, 2, 4, 6, 0, 3, 1, 7] [5, 2, 4, 7, 0, 3, 1, 6] [5, 2, 6, 1, 3, 7, 0, 4] [5, 2, 6, 1, 7, 4, 0, 3] [5, 2, 6, 3, 0, 7, 1, 4]
//         [5, 3, 0, 4, 7, 1, 6, 2] [5, 3, 1, 7, 4, 6, 0, 2] [5, 3, 6, 0, 2, 4, 1, 7] [5, 3, 6, 0, 7, 1, 4, 2] [5, 7, 1, 3, 0, 6, 4, 2]
//         [6, 0, 2, 7, 5, 3, 1, 4] [6, 1, 3, 0, 7, 4, 2, 5] [6, 1, 5, 2, 0, 3, 7, 4] [6, 2, 0, 5, 7, 4, 1, 3] [6, 2, 7, 1, 4, 0, 5, 3]
//         [6, 3, 1, 4, 7, 0, 2, 5] [6, 3, 1, 7, 5, 0, 2, 4] [6, 4, 2, 0, 5, 7, 1, 3] [7, 1, 3, 0, 6, 4, 2, 5] [7, 1, 4, 2, 0, 6, 3, 5]
//         [7, 2, 0, 5, 1, 4, 6, 3] [7, 3, 0, 2, 5, 1, 6, 4]

// Input: 3
// Output: 0
```cpp
#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    void solveSudoku(vector<vector<char>>& board) {
        solve(board);
    }

private:
    // Function to check if it's safe to place a number in the given position
    bool isSafe(vector<vector<char>>& board, int row, int col, char num) {
        // Check if the number is not in the given row and column
        for (int i = 0; i < 9; i++) {
            if (board[row][i] == num || board[i][col] == num) {
                return false;
            }
        }

        // Check the corresponding 3x3 sub-box
        int boxRow = row / 3 * 3;
        int boxCol = col / 3 * 3;
        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {
                if (board[boxRow + i][boxCol + j] == num) {
                    return false;
                }
            }
        }
        return true;
    }

    // Backtracking function to solve the Sudoku
    bool solve(vector<vector<char>>& board) {
        for (int row = 0; row < 9; row++) {
            for (int col = 0; col < 9; col++) {
                if (board[row][col] == '.') { // Find an empty cell
                    for (char num = '1'; num <= '9'; num++) { // Try numbers 1-9
                        if (isSafe(board, row, col, num)) {
                            board[row][col] = num; // Place the number
                            if (solve(board)) { // Recur to continue solving
                                return true;
                            }
                            board[row][col] = '.'; // Backtrack
                        }
                    }
                    return false; // If no number is valid, return false
                }
            }
        }
        return true; // Solved if all cells are filled
    }
};

int main() {
    // Example Sudoku puzzle
    vector<vector<char>> board = {
        {'5', '3', '.', '.', '7', '.', '.', '.', '.'},
        {'6', '.', '.', '1', '9', '5', '.', '.', '.'},
        {'.', '9', '8', '.', '.', '.', '.', '6', '.'},
        {'8', '.', '.', '.', '6', '.', '.', '.', '3'},
        {'4', '.', '.', '8', '.', '3', '.', '.', '1'},
        {'7', '.', '.', '.', '2', '.', '.', '.', '6'},
        {'.', '6', '.', '.', '.', '.', '2', '8', '.'},
        {'.', '.', '.', '4', '1', '9', '.', '.', '5'},
        {'.', '.', '.', '.', '8', '.', '.', '7', '9'}
    };

    Solution sol;
    sol.solveSudoku(board);

    // Output the solved Sudoku board
    for (const auto& row : board) {
        for (const auto& cell : row) {
            cout << cell << " ";
        }
        cout << endl;
    }

    return 0;
}
```
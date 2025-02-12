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
    // Function to solve the Sudoku using backtracking
    bool solve(vector<vector<char>>& board) {
        for (int row = 0; row < 9; ++row) {
            for (int col = 0; col < 9; ++col) {
                // Check for empty cell
                if (board[row][col] == '.') {
                    // Try placing digits 1-9
                    for (char num = '1'; num <= '9'; ++num) {
                        if (isValid(board, row, col, num)) {
                            board[row][col] = num;  // Place the number
                            if (solve(board)) {       // Continue solving
                                return true;         // Solution found
                            }
                            board[row][col] = '.';    // Backtrack
                        }
                    }
                    return false;  // No valid number found; trigger backtracking
                }
            }
        }
        return true;  // Solved the board
    }

    // Function to check if placing num on board[row][col] is valid
    bool isValid(const vector<vector<char>>& board, int row, int col, char num) {
        // Check the row and column
        for (int i = 0; i < 9; ++i) {
            if (board[row][i] == num || board[i][col] == num) {
                return false;
            }
        }

        // Check the 3x3 sub-box
        int boxRowStart = row / 3 * 3;
        int boxColStart = col / 3 * 3;
        for (int i = 0; i < 3; ++i) {
            for (int j = 0; j < 3; ++j) {
                if (board[boxRowStart + i][boxColStart + j] == num) {
                    return false;
                }
            }
        }

        return true;  // Valid placement
    }
};

int main() {
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

    // Print solved Sudoku board
    for (const auto& row : board) {
        for (char num : row) {
            cout << num << " ";
        }
        cout << endl;
    }

    return 0;
}
```
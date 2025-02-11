```cpp
#include <iostream>
#include <vector>
#include <unordered_set>

using namespace std;

class SudokuSolver {
public:
    void solveSudoku(vector<vector<char>>& board) {
        solve(board);
    }

private:
    // Function to check if placing num at (row, col) is valid
    bool isValid(const vector<vector<char>>& board, int row, int col, char num) {
        for (int i = 0; i < 9; ++i) {
            // Check the row and column
            if (board[row][i] == num || board[i][col] == num) {
                return false;
            }
            // Check the 3x3 box
            if (board[3 * (row / 3) + i / 3][3 * (col / 3) + i % 3] == num) {
                return false;
            }
        }
        return true;
    }

    // Backtracking function to solve the Sudoku
    bool solve(vector<vector<char>>& board) {
        for (int row = 0; row < 9; ++row) {
            for (int col = 0; col < 9; ++col) {
                // Find an empty cell
                if (board[row][col] == '.') {
                    for (char num = '1'; num <= '9'; ++num) {
                        // Check if it's valid to place num here
                        if (isValid(board, row, col, num)) {
                            board[row][col] = num; // Place the number

                            // Recursively attempt to solve the rest of the board
                            if (solve(board)) {
                                return true; // Solution found
                            }

                            // Backtrack
                            board[row][col] = '.'; // Reset on backtrack
                        }
                    }
                    return false; // No valid number found, triggers backtrack
                }
            }
        }
        return true; // Solution found
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

    SudokuSolver solver;
    solver.solveSudoku(board);

    // Output the solved board
    for (const auto& row : board) {
        for (const char& cell : row) {
            cout << cell << " ";
        }
        cout << endl;
    }

    return 0;
}
```
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
    // Function to solve the sudoku using backtracking
    bool solve(vector<vector<char>>& board) {
        for (int row = 0; row < 9; ++row) {
            for (int col = 0; col < 9; ++col) {
                // If we find an empty cell, try to fill it
                if (board[row][col] == '.') {
                    for (char num = '1'; num <= '9'; ++num) {
                        // Check if placing num is valid
                        if (isValid(board, row, col, num)) {
                            board[row][col] = num; // Place num

                            // Recursively try to fill in the rest
                            if (solve(board)) {
                                return true; // If successful, return true
                            }
                            
                            // If placing num didn't lead to a solution, reset the cell
                            board[row][col] = '.';
                        }
                    }
                    return false; // No valid number found, return false
                }
            }
        }
        return true; // Sudoku solved
    }
    
    // Function to check if placing num at board[row][col] is valid
    bool isValid(vector<vector<char>>& board, int row, int col, char num) {
        // Check the row and column
        for (int i = 0; i < 9; ++i) {
            if (board[row][i] == num || board[i][col] == num) {
                return false;
            }
        }
        
        // Check the 3x3 sub-box
        int startRow = row / 3 * 3;
        int startCol = col / 3 * 3;
        for (int i = startRow; i < startRow + 3; ++i) {
            for (int j = startCol; j < startCol + 3; ++j) {
                if (board[i][j] == num) {
                    return false;
                }
            }
        }
        
        return true; // Placing num is valid
    }
};

int main() {
    Solution solution;
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
    
    solution.solveSudoku(board);
    
    // Print the solved Sudoku board
    for (const auto& row : board) {
        for (const auto& num : row) {
            cout << num << ' ';
        }
        cout << endl;
    }
    
    return 0;
}
```
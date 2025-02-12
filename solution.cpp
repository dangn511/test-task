```cpp
#include <vector>
#include <string>
#include <iostream>

class Solution {
public:
    void solveSudoku(std::vector<std::vector<char>>& board) {
        solve(board);
    }

private:
    // Function to check if placing 'num' in board[row][col] is valid
    bool isValid(const std::vector<std::vector<char>>& board, int row, int col, char num) {
        // Check the row and column
        for (int i = 0; i < 9; ++i) {
            if (board[row][i] == num || board[i][col] == num) {
                return false;
            }
        }
        // Check the 3x3 sub-box
        int startRow = row - row % 3, startCol = col - col % 3;
        for (int i = 0; i < 3; ++i) {
            for (int j = 0; j < 3; ++j) {
                if (board[i + startRow][j + startCol] == num) {
                    return false;
                }
            }
        }
        return true;
    }

    // Backtracking function to solve the Sudoku
    bool solve(std::vector<std::vector<char>>& board) {
        for (int row = 0; row < 9; ++row) {
            for (int col = 0; col < 9; ++col) {
                // If we find an empty cell
                if (board[row][col] == '.') {
                    // Try digits from '1' to '9'
                    for (char num = '1'; num <= '9'; ++num) {
                        if (isValid(board, row, col, num)) {
                            // Tentatively place the number
                            board[row][col] = num;
                            // Recursively try to fill in the next empty cell
                            if (solve(board)) {
                                return true;
                            }
                            // Undo the move (backtrack)
                            board[row][col] = '.';
                        }
                    }
                    return false; // Trigger backtracking
                }
            }
        }
        return true; // Solution found
    }
};

// Example usage
int main() {
    Solution solution;
    std::vector<std::vector<char>> board = {
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
        for (char num : row) {
            std::cout << num << " ";
        }
        std::cout << std::endl;
    }

    return 0;
}
```
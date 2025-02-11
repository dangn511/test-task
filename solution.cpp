```cpp
#include <iostream>
#include <vector>

using namespace std;

// Function to check if placing 'num' at board[row][col] is valid
bool isValid(const vector<vector<char>>& board, int row, int col, char num) {
    // Check the row and column
    for (int i = 0; i < 9; ++i) {
        if (board[row][i] == num || board[i][col] == num) {
            return false;
        }
    }

    // Check the 3x3 sub-box
    int boxRowStart = (row / 3) * 3;
    int boxColStart = (col / 3) * 3;
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) {
            if (board[boxRowStart + i][boxColStart + j] == num) {
                return false;
            }
        }
    }

    return true;
}

// Backtracking function to solve the Sudoku
bool solveSudoku(vector<vector<char>>& board) {
    for (int row = 0; row < 9; ++row) {
        for (int col = 0; col < 9; ++col) {
            // Find an empty cell
            if (board[row][col] == '.') {
                // Try each digit from '1' to '9'
                for (char num = '1'; num <= '9'; ++num) {
                    if (isValid(board, row, col, num)) {
                        // Place the digit
                        board[row][col] = num;

                        // Recursively attempt to solve the rest of the Sudoku
                        if (solveSudoku(board)) {
                            return true;
                        }

                        // Backtrack if placing num doesn't lead to a solution
                        board[row][col] = '.';
                    }
                }
                // If no number can be placed, return false
                return false;
            }
        }
    }

    // If the entire board is filled correctly
    return true;
}

// Function to print the Sudoku board
void printBoard(const vector<vector<char>>& board) {
    for (const auto& row : board) {
        for (char cell : row) {
            cout << cell << " ";
        }
        cout << endl;
    }
}

int main() {
    // Define the Sudoku board
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

    // Solve the Sudoku puzzle
    if (solveSudoku(board)) {
        printBoard(board); // Output the solved Sudoku board
    } else {
        cout << "No solution exists!" << endl;
    }

    return 0;
}
```
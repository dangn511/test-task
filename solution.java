```java
public class SudokuSolver {
    public void solveSudoku(char[][] board) {
        // Begin the solving process using backtracking
        solve(board);
    }

    private boolean solve(char[][] board) {
        // Iterate through each cell in the board
        for (int row = 0; row < 9; row++) {
            for (int col = 0; col < 9; col++) {
                // Check for an empty cell represented by '.'
                if (board[row][col] == '.') {
                    // Try numbers from 1 to 9
                    for (char num = '1'; num <= '9'; num++) {
                        // Check if placing num is valid
                        if (isValid(board, row, col, num)) {
                            // Place the number on the board
                            board[row][col] = num;

                            // Recursively attempt to solve the rest of the board
                            if (solve(board)) {
                                return true; // Found a solution
                            }

                            // If no solution, reset the cell
                            board[row][col] = '.';
                        }
                    }
                    return false; // No valid number found, backtrack
                }
            }
        }
        return true; // Sudoku solved if no empty cells remain
    }

    private boolean isValid(char[][] board, int row, int col, char num) {
        // Check if 'num' exists in the current row
        for (int checkCol = 0; checkCol < 9; checkCol++) {
            if (board[row][checkCol] == num) {
                return false; // Duplicate found in the row
            }
        }

        // Check if 'num' exists in the current column
        for (int checkRow = 0; checkRow < 9; checkRow++) {
            if (board[checkRow][col] == num) {
                return false; // Duplicate found in the column
            }
        }

        // Check if 'num' exists in the current 3x3 sub-box
        int boxRowStart = (row / 3) * 3;
        int boxColStart = (col / 3) * 3;
        for (int r = boxRowStart; r < boxRowStart + 3; r++) {
            for (int c = boxColStart; c < boxColStart + 3; c++) {
                if (board[r][c] == num) {
                    return false; // Duplicate found in the sub-box
                }
            }
        }

        return true; // 'num' can be placed safely
    }
}
```
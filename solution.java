```java
public class SudokuSolver {
    // Method to solve the Sudoku puzzle
    public void solveSudoku(char[][] board) {
        solve(board);
    }

    // Helper method to recursively solve the Sudoku puzzle using backtracking
    private boolean solve(char[][] board) {
        for (int row = 0; row < 9; row++) {
            for (int col = 0; col < 9; col++) {
                // If the cell is empty
                if (board[row][col] == '.') {
                    // Try digits from 1 to 9
                    for (char digit = '1'; digit <= '9'; digit++) {
                        // Check if placing the digit here is valid
                        if (isValid(board, row, col, digit)) {
                            // Place the digit
                            board[row][col] = digit;
                            
                            // Recursively try to solve the rest of the board
                            if (solve(board)) {
                                return true;
                            }
                            // If it doesn't lead to a solution, reset the cell
                            board[row][col] = '.';
                        }
                    }
                    // If no digit can be placed, return false
                    return false;
                }
            }
        }
        // If the board is completely filled, return true
        return true;
    }

    // Method to check if a digit can be placed in the given row and column
    private boolean isValid(char[][] board, int row, int col, char digit) {
        // Check the row and column for duplicates
        for (int i = 0; i < 9; i++) {
            if (board[row][i] == digit || board[i][col] == digit) {
                return false;
            }
        }

        // Check the 3x3 sub-box for duplicates
        int boxRowStart = row - row % 3;
        int boxColStart = col - col % 3;
        for (int r = 0; r < 3; r++) {
            for (int c = 0; c < 3; c++) {
                if (board[r + boxRowStart][c + boxColStart] == digit) {
                    return false;
                }
            }
        }

        // If no duplicates found, the placement is valid
        return true;
    }
}
```
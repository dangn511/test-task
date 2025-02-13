```java
public class SudokuSolver {
    // Method to solve the Sudoku puzzle by modifying the board in place
    public void solveSudoku(char[][] board) {
        // Attempt to solve the Sudoku puzzle
        solve(board);
    }

    // Recursive method to solve the Sudoku, returns true if solved completely
    private boolean solve(char[][] board) {
        // Iterate through each cell in the 9x9 board
        for (int row = 0; row < 9; row++) {
            for (int col = 0; col < 9; col++) {
                // If we find an empty cell represented by '.'
                if (board[row][col] == '.') {
                    // Try placing digits 1-9 in the empty cell
                    for (char num = '1'; num <= '9'; num++) {
                        // Check if it's safe to place the number
                        if (isSafe(board, row, col, num)) {
                            board[row][col] = num; // Place the number
                            
                            // Recursively attempt to fill in the rest of the board
                            if (solve(board)) {
                                return true; // Return true if the board is completely solved
                            }
                            
                            // Reset the cell if placing num didn't lead to a solution
                            board[row][col] = '.'; // Backtrack
                        }
                    }
                    // If no valid number could be placed, return false to indicate failure
                    return false;
                }
            }
        }
        // If no empty cells are found, the board is fully solved
        return true;
    }

    // Method to check if it's safe to place a number in the given cell
    private boolean isSafe(char[][] board, int row, int col, char num) {
        // Check if the number is not present in the current row
        for (int x = 0; x < 9; x++) {
            if (board[row][x] == num) {
                return false;
            }
        }

        // Check if the number is not present in the current column
        for (int x = 0; x < 9; x++) {
            if (board[x][col] == num) {
                return false;
            }
        }

        // Check if the number is not present in the current 3x3 sub-grid
        int boxRowStart = row - row % 3;
        int boxColStart = col - col % 3;
        for (int r = 0; r < 3; r++) {
            for (int c = 0; c < 3; c++) {
                if (board[r + boxRowStart][c + boxColStart] == num) {
                    return false;
                }
            }
        }

        // Safe to place the number
        return true;
    }
}
```
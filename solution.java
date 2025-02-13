```java
public class SudokuSolver {
    public void solveSudoku(char[][] board) {
        if (solve(board)) {
            // Board is successfully solved
        }
    }

    private boolean solve(char[][] board) {
        for (int row = 0; row < 9; row++) {
            for (int col = 0; col < 9; col++) {
                // Check if the cell is empty
                if (board[row][col] == '.') {
                    // Try digits 1-9
                    for (char num = '1'; num <= '9'; num++) {
                        if (isValid(board, row, col, num)) {
                            // Place the number temporarily
                            board[row][col] = num;

                            // Recursively try to solve with this number
                            if (solve(board)) {
                                return true;
                            }

                            // If it didn't lead to a solution, reset the cell
                            board[row][col] = '.';
                        }
                    }
                    // If no number can be placed, return false
                    return false;
                }
            }
        }
        // Validate the filled board
        return isBoardValid(board);
    }

    private boolean isValid(char[][] board, int row, int col, char num) {
        // Check the row
        for (int i = 0; i < 9; i++) {
            if (board[row][i] == num) {
                return false;
            }
        }

        // Check the column
        for (int i = 0; i < 9; i++) {
            if (board[i][col] == num) {
                return false;
            }
        }

        // Check the 3x3 sub-box
        int boxRow = row / 3 * 3;
        int boxCol = col / 3 * 3;
        for (int i = boxRow; i < boxRow + 3; i++) {
            for (int j = boxCol; j < boxCol + 3; j++) {
                if (board[i][j] == num) {
                    return false;
                }
            }
        }

        return true;
    }

    private boolean isBoardValid(char[][] board) {
        // Check all rows, columns, and sub-boxes for validity
        for (int i = 0; i < 9; i++) {
            if (!isRowValid(board, i) || !isColumnValid(board, i) || !isSubBoxValid(board, i / 3 * 3, (i % 3) * 3)) {
                return false;
            }
        }
        return true;
    }

    private boolean isRowValid(char[][] board, int row) {
        boolean[] seen = new boolean[9];
        for (int col = 0; col < 9; col++) {
            char num = board[row][col];
            if (num != '.') {
                if (seen[num - '1']) {
                    return false; // Duplicate found
                }
                seen[num - '1'] = true;
            }
        }
        return true;
    }

    private boolean isColumnValid(char[][] board, int col) {
        boolean[] seen = new boolean[9];
        for (int row = 0; row < 9; row++) {
            char num = board[row][col];
            if (num != '.') {
                if (seen[num - '1']) {
                    return false; // Duplicate found
                }
                seen[num - '1'] = true;
            }
        }
        return true;
    }

    private boolean isSubBoxValid(char[][] board, int startRow, int startCol) {
        boolean[] seen = new boolean[9];
        for (int row = startRow; row < startRow + 3; row++) {
            for (int col = startCol; col < startCol + 3; col++) {
                char num = board[row][col];
                if (num != '.') {
                    if (seen[num - '1']) {
                        return false; // Duplicate found
                    }
                    seen[num - '1'] = true;
                }
            }
        }
        return true;
    }
}
```
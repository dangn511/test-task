```java
public class SudokuSolver {
    
    private static final int SIZE = 9; // Size of the Sudoku grid
    private static final char EMPTY = '.'; // Represents an empty cell

    public void solveSudoku(char[][] board) {
        if (board == null || board.length != SIZE || board[0].length != SIZE) {
            throw new IllegalArgumentException("Invalid board size. It must be a 9x9 grid.");
        }
        solve(board);
    }

    private boolean solve(char[][] board) {
        // Iterate through each cell in the board
        for (int row = 0; row < SIZE; row++) {
            for (int col = 0; col < SIZE; col++) {
                // Check for an empty cell
                if (board[row][col] == EMPTY) {
                    // Try numbers from 1 to 9
                    for (char num = '1'; num <= '9'; num++) {
                        // If the number can be placed
                        if (isValid(board, row, col, num)) {
                            board[row][col] = num; // Place the number

                            // Recursively attempt to fill the rest of the board
                            if (solve(board)) {
                                return true; // Return true if solved
                            }

                            // If not solvable, backtrack
                            board[row][col] = EMPTY; // Reset the cell
                        }
                    }
                    return false; // If no number can be placed, return false
                }
            }
        }
        return true; // The board is completely filled
    }

    private boolean isValid(char[][] board, int row, int col, char num) {
        return !isInRow(board, row, num) && 
               !isInCol(board, col, num) && 
               !isInBox(board, row - row % 3, col - col % 3, num);
    }

    private boolean isInRow(char[][] board, int row, char num) {
        for (int col = 0; col < SIZE; col++) {
            if (board[row][col] == num) {
                return true; // Number found in the row
            }
        }
        return false; // Number not found in the row
    }

    private boolean isInCol(char[][] board, int col, char num) {
        for (int row = 0; row < SIZE; row++) {
            if (board[row][col] == num) {
                return true; // Number found in the column
            }
        }
        return false; // Number not found in the column
    }

    private boolean isInBox(char[][] board, int boxStartRow, int boxStartCol, char num) {
        for (int row = 0; row < 3; row++) {
            for (int col = 0; col < 3; col++) {
                if (board[row + boxStartRow][col + boxStartCol] == num) {
                    return true; // Number found in the 3x3 box
                }
            }
        }
        return false; // Number not found in the 3x3 box
    }

    public static void main(String[] args) {
        SudokuSolver solver = new SudokuSolver();
        char[][] board = {
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
        
        solver.solveSudoku(board);

        // Print the solved board in a clear format
        for (char[] row : board) {
            System.out.println(String.valueOf(row));
        }
    }
}
```
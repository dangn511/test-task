```python
def solveSudoku(board):
    """
    Solves a Sudoku puzzle by filling the empty cells.
    
    Args:
    board (List[List[str]]): A 9x9 2D list representing the Sudoku board, where '.' indicates empty cells.
    
    Returns:
    None: The board is modified in place to contain the solution.
    """

    def is_valid(num, row, col):
        """Check if it's valid to place num in the given row and column."""
        for i in range(9):
            if board[row][i] == num:  # Check row
                return False
            if board[i][col] == num:  # Check column
                return False
            # Check 3x3 sub-box
            if board[3 * (row // 3) + i // 3][3 * (col // 3) + i % 3] == num:
                return False
        return True

    def backtrack():
        """Try to fill the board with valid numbers using backtracking."""
        for row in range(9):
            for col in range(9):
                if board[row][col] == '.':
                    for num in '123456789':
                        if is_valid(num, row, col):
                            board[row][col] = num  # Place the number
                            if backtrack():  # Recur to continue solving
                                return True
                            board[row][col] = '.'  # Undo placement (backtrack)
                    return False  # No valid number found; trigger backtrack
        return True  # Return True when the entire board is filled

    backtrack()  # Start the backtracking algorithm
```
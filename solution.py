Below is the JavaScript code to solve a Sudoku puzzle. 

The key idea of the algorithm is to use a depth-first search to place numbers on the board. When placing a number, we check whether it violates the Sudoku rules. If it does, we remove the number and try the next one. If we cannot put a number in the current cell, we backtrack to the previous cell and put the next number in it. If the number is valid, we move to the next cell.

```javascript
function solveSudoku(board) {
  if (board.length !== 9 || board[0].length !== 9) return;
  
  // Use depth-first search to fill the board
  dfs(board, 0, 0);

  function dfs(board, row, col) {
    // If we have filled all cells, return true
    if (row === 9) return true;
    
    // If this column is filled, move to next column
    if (col === 9) return dfs(board, row + 1, 0);
    
    // If this cell is empty
    if (board[row][col] === '.') {
      // Try numbers from 1 to 9
      for (let num = 1; num <= 9; num++) {
        // Check whether it's valid to put this number here
        if (isValid(board, row, col, String(num))) {
          // Put this number
          board[row][col] = String(num);
          // Continue to fill next cell
          if (dfs(board, row, col + 1)) return true;
          // Backtrack, because we could not fill next cells with this number
          board[row][col] = '.';
        }
      }
    } else {
      // Continue to fill next cell
      return dfs(board, row, col + 1);
    }

    return false;
  }

  function isValid(board, row, col, num) {
    for (let i = 0; i < 9; i++) {
      // Check this row
      if (board[i][col] === num) return false;
      // Check this column
      if (board[row][i] === num) return false;
      // Check this 3 x 3 box
      if (board[3 * Math.floor(row / 3) + Math.floor(i / 3)][3 * Math.floor(col / 3) + i % 3] === num) return false;
    }
    // It's valid to put this number here
    return true;
  }
}
```

The `dfs` function defines the depth-first search, and the `isValid` subroutine checks whether a candidate number violates the Sudoku rules. The solution starts at the top left cell and moves to the right until it reaches the last cell in a row, then it wraps to the leftmost cell of the next row. If all cells are filled (i.e., `row == 9`), the function returns `true` to signal the Sudoku is solved.
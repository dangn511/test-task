Here is the javascript function to solve the Sudoku:

```javascript
const solveSudoku = function(board) {
  if (board == null || board.length == 0)
    return;
    
  solve(board);
};

const solve = function(board) {
  // iterate through the board row by row, cell by cell
  for (let i = 0; i < board.length; i++) {
    for (let j = 0; j < board[0].length; j++) {
      // find the cell with '.' character
      if (board[i][j] == '.') {
        // try possibilities from 1 to 9 
        // that does not violate sudoku constraints
        for (let c = '1'; c <= '9'; c++) {
          if (isValid(board, i, j, c)) {
            board[i][j] = `${c}`;
            // if it is the solution, return true
            if (solve(board))
              return true;
            else // backtrack when not a solution
              board[i][j] = '.';
          }
        }
        // no valid numbers can be placed, return false
        return false;
      }
    }
  }
  // no more '.' character cell to assign values, solution found
  return true;
};

// validate whether it is valid to put character c in cell i, j
const isValid = function(board, row, col, c) {
  for (let i = 0; i < 9; i++) {
    // check column
    if (board[i][col] != '.' && board[i][col] == `${c}`) 
      return false;
    // check row
    if (board[row][i] != '.' && board[row][i] == `${c}`) 
      return false;
    // check 3*3 block
    if (board[3 * Math.floor(row / 3) + Math.floor(i / 3)][3 * Math.floor(col / 3) + i % 3] != '.' && 
        board[3 * Math.floor(row / 3) + Math.floor(i / 3)][3 * Math.floor(col / 3) + i % 3] == `${c}`) 
      return false;
  }
  return true;
};
```

This program uses a depth-first search (DFS) strategy to solve the Sudoku.
It tries possibilities from 1 to 9 for each '.' cell and recurrently checks whether the current board is solvable. 
If the attempted number is valid (satisfy all sudoku rules), the function calls itself trying to fill the next empty cell.  If the function cannot find a possible number (1-9) that satisfies the Sudoku rules, it returns false to its previous state (changes cell back to '.') and then tries the next potential number.
This is a classic backtracking method. Each time a path is chosen, the function keeps going down this path until an end. If there is deadlock, it will go back to the nearest choice point and try other paths again.
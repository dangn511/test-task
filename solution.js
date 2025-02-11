```javascript
// Function to solve Sudoku
function solveSudoku(board) {
  // Iterate through the board
  for (let i = 0; i < 9; i++) {
    for (let j = 0; j < 9; j++) {
      // If current cell is empty '.'
      if (board[i][j] === '.') {
        // Try digits from 1 to 9
        for (let k = 1; k <= 9; k++) {
          // If k is valid in the current cell
          if (isValid(board, i, j, String(k))) {
            // Assign k to the current cell
            board[i][j] = String(k);
            // Move to next cell
            if (solveSudoku(board)) {
              return true;
            }
            // If not a solution, reset the cell
            board[i][j] = '.';
          }
        }
        return false;
      }
    }
  }
  return true;
}

// Helper function to check if n is valid in the cell at the ith row and jth column
function isValid(board, row, col, n) {
  // Check the row
  for (let i = 0; i < 9; i++) {
    if (board[i][col] === n) {
      return false;
    }
  }
  // Check the column
  for (let j = 0; j < 9; j++) {
    if (board[row][j] === n) {
      return false;
    }
  }
  // Check the square box
  let startRow = 3 * Math.floor(row / 3);
  let startCol = 3 * Math.floor(col / 3);
  for (let i = 0; i < 3; i++) {
    for (let j = 0; j < 3; j++) {
      if (board[i + startRow][j + startCol] === n) {
        return false;
      }
    }
  }
  // N is valid in the cell
  return true;
}
```
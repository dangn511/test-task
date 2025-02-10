```javascript
function solveSudoku(board) {
    solve();

    function solve() {
        for (let i = 0; i < 9; i++) {
            for (let j = 0; j < 9; j++) {
                if (board[i][j] === '.') {
                    for (let k = 1; k <= 9; k++) {
                        // trial. Try 1 through 9 for each cell
                        if (isValid(board, i, j, k)) {
                            board[i][j] = `${k}`;
                        // if it's the solution and there's no violations, keep going
                            if (solve()) {
                                return true;
                        }
                        // otherwise change it back
                            else {
                                board[i][j] = '.';
                            }
                        }
                    }
                    // we've tried 1-9 for current cell, solutions do not work, return false to try next number for previous cell
                    return false;
                }
            }
        }
        // all numbers are valid in the current board, return true to start next backtracking process
        return true;
    }

    function isValid(board, row, col, c) {
        for (let i = 0; i < 9; i++) {
            if (board[i][col] === `${c}`) { // check column
                return false;
            }
            if (board[row][i] === `${c}`) { // check row
                return false;
            }
            if (board[3 * Math.floor(row / 3) + Math.floor(i / 3)][3 * Math.floor(col / 3) + i % 3] === `${c}`){ // check 3*3 block
                return false;
            }
        }
        return true;
    }
}
```
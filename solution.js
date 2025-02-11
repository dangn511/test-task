```javascript
function solveSudoku(board) {

    function is_valid(board, row, col, num) {
        // Check the number in the row
        for (let i = 0; i < 9; i++) {
            let m = Math.floor(row / 3) * 3 + Math.floor(i / 3);
            let n = Math.floor(col / 3) * 3 + i % 3;
            if (board[row][i] == num || board[i][col] == num || board[m][n] == num){
                return false;
            } 
        }
        return true;
    }

    function solve(board) {
        for (let i = 0; i < 9; i++) {
            for (let j = 0; j < 9; j++) {
                if (board[i][j] == '.') {
                    for (let num = 1; num <= 9; num++){
                        if (is_valid(board, i, j, num)) {
                            board[i][j] = `${num}`;
                            if (solve(board)){
                                return true;
                            }
                            board[i][j] = '.';
                        }
                    }
                    return false;
                }
            }
        }
        return true;
    }

    solve(board);
}


//Test the Sudoku solver function with an example
solveSudoku([["5","3",".",".","7",".",".",".","."],
             ["6",".",".","1","9","5",".",".","."],
             [".","9","8",".",".",".",".","6","."],
             ["8",".",".",".","6",".",".",".","3"],
             ["4",".",".","8",".","3",".",".","1"],
             ["7",".",".",".","2",".",".",".","6"],
             [".","6",".",".",".",".","2","8","."],
             [".",".",".","4","1","9",".",".","5"],
             [".",".",".",".","8",".",".","7","9"]]);
```

This JavaScript function will solve a given Sudoku puzzle using backtracking. It checks for a valid placement of a number in a Sudoku's grid and if it finds a valid number, it tries to place it. If it cannot find a valid number for a cell, it will backtrack, changing the previously filled cells and try other possible numbers.
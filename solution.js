```Javascript
function isValid(board, row, col, num) {
    for(let x = 0; x < 9; x++) {
        const m = 3 * Math.floor(row / 3) + Math.floor(x / 3);
        const n = 3 * Math.floor(col / 3) + x % 3;
        if(board[row][x] == num || board[x][col] == num || board[m][n] == num) {
            return false;
        }
    }
    return true;
}

function solve(board) {
    for(let i = 0; i < 9; i++) {
        for(let j = 0; j < 9; j++) {
            if(board[i][j] == '.') {
                for(let num = 1; num <= 9; num++) {
                    if(isValid(board, i ,j, num)) {
                        board[i][j] = ''+num;
                        if(solve(board)) {
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

// Use solve function to the sudoku puzzle and modify the existing matrix.
// input
let board = [
    ["5","3",".",".","7",".",".",".","."],
    ["6",".",".","1","9","5",".",".","."],
    [".","9","8",".",".",".",".","6","."],
    ["8",".",".",".","6",".",".",".","3"],
    ["4",".",".","8",".","3",".",".","1"],
    ["7",".",".",".","2",".",".",".","6"],
    [".","6",".",".",".",".","2","8","."],
    [".",".",".","4","1","9",".",".","5"],
    [".",".",".",".","8",".",".","7","9"]
    ];
solve(board);
console.log(board);
```
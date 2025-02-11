```javascript
function solveSudoku(board) {
    // Helper function to check if placing num in board[row][col] is valid
    function isValid(board, row, col, num) {
        // Check the row and column
        for (let i = 0; i < 9; i++) {
            if (board[row][i] === num || board[i][col] === num) {
                return false;
            }
        }
        // Check the 3x3 sub-box
        const boxRowStart = Math.floor(row / 3) * 3;
        const boxColStart = Math.floor(col / 3) * 3;
        for (let i = boxRowStart; i < boxRowStart + 3; i++) {
            for (let j = boxColStart; j < boxColStart + 3; j++) {
                if (board[i][j] === num) {
                    return false;
                }
            }
        }
        return true;
    }
    
    // Recursive backtracking function to solve the Sudoku
    function solve(board) {
        for (let row = 0; row < 9; row++) {
            for (let col = 0; col < 9; col++) {
                if (board[row][col] === '.') { // Find an empty cell
                    for (let num = 1; num <= 9; num++) { // Try all numbers from 1 to 9
                        const strNum = num.toString();
                        if (isValid(board, row, col, strNum)) {
                            board[row][col] = strNum; // Place the number
                            if (solve(board)) { // Recursively attempt to solve the rest
                                return true;
                            }
                            board[row][col] = '.'; // Reset if it doesn't lead to a solution
                        }
                    }
                    return false; // Trigger backtracking
                }
            }
        }
        return true; // Solved
    }

    solve(board); // Initiate the solving process
}

// Example usage:
const board = [
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

solveSudoku(board);
console.log(board); // Output the solved board
```
class Solution {
public:
    
    bool isSafe(int row, int col, vector<vector<char>>& board, char val) {
        int n = board.size();

        for (int i = 0; i < n; i++) {

            // Row check
            if (board[row][i] == val)
                return false;

            // Column check
            if (board[i][col] == val)
                return false;

            // 3x3 Box check
            if (board[3 * (row / 3) + i / 3][3 * (col / 3) + i % 3] == val)
                return false;
        }
        return true;
    }

    bool solve(vector<vector<char>>& board) {

        int n = board.size();

        for (int row = 0; row < n; row++) {
            for (int col = 0; col < n; col++) {

                if (board[row][col] == '.') {

                    for (char val = '1'; val <= '9'; val++) {

                        if (isSafe(row, col, board, val)) {

                            board[row][col] = val;

                            if (solve(board))
                                return true;

                            board[row][col] = '.';
                        }
                    }

                    // No number can be placed
                    return false;
                }
            }
        }

        // No empty cell left
        return true;
    }

    void solveSudoku(vector<vector<char>>& board) {
        solve(board);
    }
};
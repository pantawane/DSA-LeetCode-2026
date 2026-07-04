class Solution {
public:
    bool isSafe(int row, int col, vector<vector<char>> &board, int n) {

        int x = row;
        int y = col;

        // Left row
        while (y >= 0) {
            if (board[x][y] == 'Q')
                return false;
            y--;
        }

        // Upper-left diagonal
        x = row;
        y = col;

        while (x >= 0 && y >= 0) {
            if (board[x][y] == 'Q')
                return false;
            x--;
            y--;
        }

        // Lower-left diagonal
        x = row;
        y = col;

        while (x < n && y >= 0) {
            if (board[x][y] == 'Q')
                return false;
            x++;
            y--;
        }

        return true;
    }

    void solve(int col, vector<vector<char>> &board, int n, int &count) {

        if (col == n) {
            count++;
            return;
        }

        for (int row = 0; row < n; row++) {

            if (isSafe(row, col, board, n)) {

                board[row][col] = 'Q';

                solve(col + 1, board, n, count);

                board[row][col] = '.';
            }
        }
    }

    int totalNQueens(int n) {

        vector<vector<char>> board(n, vector<char>(n, '.'));

        int count = 0;

        solve(0, board, n, count);

        return count;
    }
};
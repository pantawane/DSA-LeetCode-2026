class Solution {
private:
    void bfs(queue<pair<int, int>> &q, vector<vector<char>>& board, vector<vector<int> > &visited){
        int n = board.size();
        int m = board[0].size();

        int delRow[] = {-1, 0, 1, 0};
        int delCol[] = {0, 1, 0, -1};

        while(!q.empty()){
            int row = q.front().first;
            int col = q.front().second;
            q.pop();

            for(int i=0; i<4; i++){
                int nrow = row + delRow[i];
                int ncol = col + delCol[i];

                if(nrow >=0 && nrow <n && ncol >=0 && ncol <m &&
                !visited[nrow][ncol] && board[nrow][ncol] == 'O'){
                    visited[nrow][ncol] = 1;
                    q.push({nrow, ncol});
                }
            }
        }
    }
public:
    void solve(vector<vector<char>>& board) {
        if(board.empty()) return;

        int n = board.size();
        int m = board[0].size();

        vector<vector<int> > visited(n, vector<int> (m,0));

        queue<pair<int, int>> q;

        // top row
        for(int j=0; j<m; j++){
            if(board[0][j] == 'O'){
                visited[0][j] = 1;
                q.push({0,j});
            }
        }
        // left col
        for(int i=1; i<n; i++){
            if(board[i][0] == 'O'){
                visited[i][0] = 1;
                q.push({i,0});
            }
        }
        //bottom row
        for(int j=0; j<m; j++){
            if(board[n-1][j] == 'O'){
                visited[n-1][j] = 1;
                q.push({n-1, j});
            }
        }
        //right col
        for(int i=0; i<n-1; i++){
            if(board[i][m-1] == 'O'){
                visited[i][m-1] = 1;
                q.push({i, m-1});
            }
        }
        bfs(q, board, visited);

        //Convert all 'O' into queue and replace with 'X'
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){

                if(board[i][j] == 'O' && !visited[i][j] ){
                    board[i][j] = 'X';
                }
            }
        }
        
    }
};
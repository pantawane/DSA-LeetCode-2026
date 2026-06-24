class Solution {
public:
    void bfs(int row, int col, vector<vector<int>> &vis, vector<vector<char>>& grid){
        vis[row][col] = 1;
        //create queue
        queue<pair<int, int>> q;
        q.push({row, col});

        while(!q.empty()){
            int row = q.front().first;
            int col = q.front().second;
            q.pop();
            int n = grid.size();
            int m = grid[0].size();

            //traverse in the neighbour and mark them if its a land
                int delrow[] = {-1, 0, 1, 0}; //up right down left
                int delcol[] = {0, 1, 0, -1};
                for(int i = 0; i < 4; i++){
                    int nrow = row + delrow[i];
                    int ncol = col + delcol[i];

                    if(nrow >= 0 && nrow < n && ncol >=0 && ncol < m && grid[nrow][ncol] == '1' && !vis[nrow][ncol]){
                        vis[nrow][ncol] = 1;
                        q.push({nrow, ncol});
                    }
                }
        }

    }

    int numIslands(vector<vector<char>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        //create visited 2d array
        vector<vector<int>> vis(n, vector<int> (m, 0));
        int cnt = 0;
        for(int row=0; row<n; row++){
            for(int col=0; col<m; col++){
                if(!vis[row][col] && grid[row][col] == '1'){
                    bfs(row, col, vis, grid);
                    cnt++;
                }
            }
        }
        return cnt;
    }
};
class Solution {
private:
    int bfs(queue<pair<int, int>> &q, vector<vector<int>>& grid){
        int n = grid.size();
        int m = grid[0].size();

        int delRow[] = {-1, 0, 1, 0};
        int delCol[] = {0, 1, 0, -1};

        int minutes = 0;

        while(!q.empty()){
            //for each bfs traversal we have to check minutes so for each push in queue we have to check its size so
            int size = q.size();

            while(size --){
                int row = q.front().first;
                int col = q.front().second;
                q.pop();

                for(int i =0; i<4; i++){
                    int nrow = row + delRow[i];
                    int ncol = col + delCol[i];

                    if(nrow >=0 && nrow < n && ncol >=0 && ncol < m &&
                    grid[nrow][ncol] == 1){
                        grid[nrow][ncol] = 2;
                        q.push({nrow, ncol});
                    }
                }
            }
            if(!q.empty())
            minutes++;
        }
        return minutes;
    }
public:
    int orangesRotting(vector<vector<int>>& grid) {
        if(grid.empty()) return 0;

        int n = grid.size();
        int m = grid[0].size();

        queue<pair<int, int>> q;
       // push all rotten oranges in a queue
        for(int i=0; i< n; i++){
            for(int j =0; j<m; j++){
                if(grid[i][j] == 2){
                    q.push({i, j});
                }
            }
        }
        //check any fresh oranges remain
        int minutes = bfs(q, grid);
        for(int i=0; i< n; i++){
            for(int j =0; j<m; j++){
                if(grid[i][j] == 1){
                   return -1;
                }
            }
        }
        return minutes;
    }
};
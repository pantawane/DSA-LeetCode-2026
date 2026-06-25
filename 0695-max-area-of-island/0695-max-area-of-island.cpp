class Solution {
private:
    int bfs(int row, int col, vector<vector<int>> &visited, vector<vector<int>>& grid){
        visited[row][col] = 1;
        int area = 1;

        queue<pair<int, int>> q;
        q.push({row, col});
        
        while(!q.empty()){
            int row = q.front().first;
            int col = q.front().second;
            q.pop();
            int n = grid.size();
            int m = grid[0].size();


            //find neighbour 
            int delRow[] = {-1, 0, 1, 0};
            int delCol[] = {0, 1, 0, -1};

            for(int i=0; i<4; i++){
                int nrow = row + delRow[i];
                int ncol = col + delCol[i];

                if(nrow >= 0 && nrow < n && ncol >=0 && ncol < m &&
                 !visited[nrow][ncol] && grid[nrow][ncol] == 1){
                    visited[nrow][ncol] = 1;
                    q.push({nrow, ncol});
                    area++;
                 }
            }
        }
        return area;
    }

public:
    int maxAreaOfIsland(vector<vector<int>>& grid) {

        //base case
        if(grid.empty())
        return 0;

        int n = grid.size();
        int m = grid[0].size();
        int maxArea = 0;

        vector<vector<int>> visited(n, vector<int> (m,0));
        for(int row=0; row<n; row++){
            for(int col =0; col<m; col++){
                if(!visited[row][col] && grid[row][col] == 1){
                    int area = bfs(row, col, visited, grid);
                    maxArea = max(maxArea, area);
                }
            }
        }
        return maxArea;
    }
};

class Solution {
private:
    void bfs(queue<pair<int, int>> &q, vector<vector<int>>& heights, vector<vector<int>> &visited){
        int n = heights.size();
        int m = heights[0].size();

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
                !visited[nrow][ncol] && heights[nrow][ncol] >= heights[row][col]){
                    visited[nrow][ncol] = 1;
                    q.push({nrow, ncol});
                }
            }
        }
    }
public:
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        int n = heights.size();
        int m = heights[0].size();

        vector<vector<int>> pacific(n, vector<int> (m,0));
        vector<vector<int>> atlantic(n, vector<int> (m,0));

        queue<pair<int, int>> pq;
        queue<pair<int, int>> aq;

        //Pacific ->top row
        for(int j =0; j< m; j++){
            pacific[0][j] = 1;
            pq.push({0,j});
        }

        //Pacific -> left col
        for(int i=1; i< n; i++){
            pacific[i][0] = 1;
            pq.push({i,0});
        }

        //Atlantic -> right col
        for(int i=0; i<n-1; i++){
            atlantic[i][m-1] = 1;
            aq.push({i, m-1});  /// todo
        }

        //Atlantic -> bottom row
        for(int j=0; j<m; j++){
            atlantic[n-1][j] = 1;
            aq.push({n-1, j});   ///todo
        }

        bfs(pq, heights, pacific);
        bfs(aq, heights, atlantic);

        vector<vector<int>> ans;

        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(pacific[i][j] && atlantic[i][j]){
                    ans.push_back({i,j});
                }
                
            }
        }
        return ans;
    }
};
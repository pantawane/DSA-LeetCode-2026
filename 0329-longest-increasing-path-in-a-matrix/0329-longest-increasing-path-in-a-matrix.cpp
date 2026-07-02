class Solution {
public:
    int dfs(int i, int j, vector<vector<int>>& matrix, vector<vector<int>> &dp){
        int n = matrix.size();
        int m = matrix[0].size();

        int delRow[] = {-1, 0, 1, 0};
        int delCol[] = {0, 1, 0, -1};

        if(dp[i][j] != -1)
        return dp[i][j];

        int ans = 1;
        for(int k =0; k<4; k++){
            int newRow = i + delRow[k];
            int newCol  = j + delCol[k];

            if(newRow >= 0 && newRow < n && newCol >= 0 && newCol < m && matrix[newRow][newCol] > matrix[i][j]){
                ans = max(ans, 1 + dfs(newRow, newCol, matrix, dp));
            }
        }
        return dp[i][j] = ans;
    }

    int longestIncreasingPath(vector<vector<int>>& matrix) {
        int n = matrix.size();
        int m = matrix[0].size();
        vector<vector<int>> dp(n, vector<int> (m, -1));
        int maxi = 0;

        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                maxi = max(maxi, dfs(i, j, matrix, dp));
            }
        }
        return maxi;
    }
};
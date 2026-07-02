class Solution {
public:
      int solve(int i, int j, vector<vector<int>>& obstacleGrid){
        //base case
        if(i >= 0 && j >= 0 && obstacleGrid[i][j] == 1)
        return 0;
        if(i == 0 && j== 0)
        return 1;
        if(i< 0 || j < 0)
        return 0;

        int up = solve(i-1, j, obstacleGrid);
        int left = solve(i, j-1, obstacleGrid);

        return up + left;
    }
    //memoization
    int solveMem(int i, int j, vector<vector<int>>& obstacleGrid, vector<vector<int>> &dp){
        //base case
        if(i >= 0 && j >= 0 && obstacleGrid[i][j] == 1)
        return 0;
        if(i == 0 && j== 0)
        return 1;
        if(i< 0 || j < 0)
        return 0;

        if(dp[i][j] != -1)
        return dp[i][j];

        int up = solveMem(i-1, j,obstacleGrid, dp);
        int left = solveMem(i, j-1,obstacleGrid, dp);

        return dp[i][j] = up + left;
    }

    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int m = obstacleGrid.size();
        int n = obstacleGrid[0].size();
        // return solve(m-1, n-1, obstacleGrid)
        vector<vector<int>> dp(m, vector<int> (n, -1));
        return solveMem(m-1, n-1, obstacleGrid, dp);
    }
};
class Solution {
public:
    int solve(int i, int j, vector<vector<int>>& triangle){
        int n = triangle.size();
        //base case
        if(i == n-1)
        return triangle[n-1][j];

        int down = triangle[i][j] + solve(i+1, j, triangle);
        int diagonal = triangle[i][j] + solve(i+1, j+1, triangle);

        return min(down, diagonal);
    }
    //memoization
    int solveMem(int i, int j, vector<vector<int>>& triangle, vector<vector<int>> &dp){
        int n = triangle.size();
        //base case
        if(i == n-1)
        return triangle[n-1][j];

        if(dp[i][j] != -1)
        return dp[i][j];

        int down = triangle[i][j] + solveMem(i+1, j, triangle, dp);
        int diagonal = triangle[i][j] + solveMem(i+1, j+1, triangle, dp);

        return dp[i][j] = min(down, diagonal);
    }
    //tabulation
    int solveTab(vector<vector<int>>& triangle){
        int n = triangle.size();
        vector<vector<int>> dp(n+1, vector<int> (n+1, 0));
        //base case analyze
        for(int j=0; j<n; j++){
            dp[n-1][j] = triangle[n-1][j];
        }

        for(int i = n-2; i>=0; i--){
            for(int j = i; j >= 0; j--){
                int down = triangle[i][j] + dp[i+1][j];
                int diagonal = triangle[i][j] + dp[i+1][j+1];

                dp[i][j] = min(down, diagonal);
            }
        }
        return dp[0][0];
    }

    int minimumTotal(vector<vector<int>>& triangle) {
        //return solve(0, 0, triangle);
        int n = triangle.size();
        //vector<vector<int>> dp(n, vector<int> (n, -1));
        //return solveMem(0, 0, triangle, dp);
        return solveTab(triangle);
    }
};
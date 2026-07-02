class Solution {
public:
    int solve(int i, int j){
        //base case
        if(i == 0 && j== 0)
        return 1;
        if(i< 0 || j < 0)
        return 0;

        int up = solve(i-1, j);
        int left = solve(i, j-1);

        return up + left;
    }
    //memoization
    int solveMem(int i, int j, vector<vector<int>> &dp){
        //base case
        if(i == 0 && j== 0)
        return 1;
        if(i< 0 || j < 0)
        return 0;

        if(dp[i][j] != -1)
        return dp[i][j];

        int up = solveMem(i-1, j, dp);
        int left = solveMem(i, j-1, dp);

        return dp[i][j] = up + left;
    }

    int uniquePaths(int m, int n) {
        // return solve(m-1, n-1);
        vector<vector<int>> dp(m, vector<int> (n, -1));
        return solveMem(m-1, n-1, dp);
    }
};
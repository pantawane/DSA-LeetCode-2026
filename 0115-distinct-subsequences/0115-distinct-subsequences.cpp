class Solution {
public:
    int solve(string &s, string &t, int i, int j){
        if(j < 0) return 1;
        if(i < 0) return 0;

        if(s[i] == t[j]){
           return solve(s, t, i-1, j-1) + solve(s, t, i-1, j);
        }
        return solve(s, t, i-1, j);
    }
    //memoization
    int solveMem(string &s, string &t, int i, int j, vector<vector<int>> &dp){
        if(j < 0) return 1;
        if(i < 0) return 0;

        if(dp[i][j] != -1)
        return dp[i][j];

        if(s[i] == t[j]){
           return dp[i][j] = solveMem(s, t, i-1, j-1, dp) + solveMem(s, t, i-1, j, dp);
        }
        return dp[i][j] = solveMem(s, t, i-1, j, dp);
    }

    int numDistinct(string s, string t) {
        int n = s.size();
        int m = t.size();
        // return solve(s, t, n-1, m-1);
        vector<vector<int>> dp(n, vector<int> (m, -1));
        return solveMem(s, t, n-1, m-1, dp);
    }
};
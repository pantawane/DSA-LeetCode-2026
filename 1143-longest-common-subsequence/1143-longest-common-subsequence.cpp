class Solution {
public:
// recursion
    int solve(string &a, string &b, int i, int j){
        //base case
        if(i == a.length())
        return 0;
        if(j == b.length())
        return 0;

        int ans = 0;
        if(a[i] == b[j]){
            ans = 1 + solve(a, b, i+1, j+1);
        }else{
            ans = max(solve(a, b, i+1, j), solve(a, b, i, j+1));
        }
        return ans;
    }
    //memoization
    int solveMem(string &a, string &b, int i, int j, vector<vector<int>> &dp){
        //base case
        if(i == a.length())
        return 0;
        if(j == b.length())
        return 0;

        if(dp[i][j] != -1)
        return dp[i][j];

        int ans = 0;
        if(a[i] == b[j]){
            ans = 1 + solveMem(a, b, i+1, j+1, dp);
        }else{
            ans = max(solveMem(a, b, i+1, j, dp), solveMem(a, b, i, j+1, dp));
        }
        return dp[i][j] = ans;
    }

    int longestCommonSubsequence(string text1, string text2) {
        //return solve(text1, text2, 0, 0);
        vector<vector<int>> dp(text1.length(), vector<int> (text2.length(), -1));
        return solveMem(text1, text2, 0, 0, dp);
    }
};
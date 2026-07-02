class Solution {
public:
    bool solve(int i, int j, string &s1, string &s2, string &s3){
        //base case
        if(i == s1.length() && j == s2.length())
        return true;

        int k = i+j;
        //for s1
        if(i < s1.length() && s1[i] == s3[k]){
            if(solve(i+1, j, s1, s2, s3))
            return true;
        }
        //for s2
        if(j < s2.length() && s2[j] == s3[k]){
            if(solve(i, j+1, s1, s2, s3))
            return true;
        }
        return false;
    }
    //memoization
    bool solveMem(int i, int j, string &s1, string &s2, string &s3, vector<vector<int>> &dp){
        //base case
        if(i == s1.length() && j == s2.length())
        return true;

        int k = i+j;
        if(dp[i][j] != -1)
        return dp[i][j];

        //for s1
        if(i < s1.length() && s1[i] == s3[k]){
            if(solveMem(i+1, j, s1, s2, s3, dp))
            return dp[i][j] = true;
        }
        //for s2
        if(j < s2.length() && s2[j] == s3[k]){
            if(solveMem(i, j+1, s1, s2, s3, dp))
            return dp[i][j] = true;
        }
        return dp[i][j] = false;
    }

    bool isInterleave(string s1, string s2, string s3) {
        if(s1.length() + s2.length() != s3.length())
        return false;

        vector<vector<int>> dp(s1.length() + 1, vector<int> (s2.length() + 1, -1));
        return solveMem(0, 0, s1, s2, s3, dp);
    }
};
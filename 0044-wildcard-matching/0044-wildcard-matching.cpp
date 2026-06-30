class Solution {
public:
    bool solve(string &str, string &pattern, int i, int j){
        //base case
        if(i < 0 && j < 0)
        return true;

        if(i>=0 && j<0)
        return false;

        if(i<0 && j >= 0){
            for(int k=0; k<=j; k++){
                if(pattern[k] != '*'){
                    return false;
                }
            }
            return true;
        }

        //match
        if(str[i] == pattern[j] || pattern[j] == '?')
            return solve(str, pattern, i-1, j-1);
        else if(pattern[j] == '*')
            return (solve(str, pattern, i, j-1) || solve(str, pattern, i-1, j));
        else
            return false;
    }
    //memoization
    bool solveMem(string &str, string &pattern, int i, int j, vector<vector<int>> &dp){
        //base case
        if(i < 0 && j < 0)
        return true;

        if(i>=0 && j<0)
        return false;

        if(i<0 && j >= 0){
            for(int k=0; k<=j; k++){
                if(pattern[k] != '*'){
                    return false;
                }
            }
            return true;
        }

        if(dp[i][j] != -1)
        return dp[i][j];

        //match
        if(str[i] == pattern[j] || pattern[j] == '?')
            return dp[i][j] = solveMem(str, pattern, i-1, j-1, dp);
        else if(pattern[j] == '*')
            return dp[i][j] = (solveMem(str, pattern, i, j-1, dp) || solveMem(str, pattern, i-1, j, dp));
        else
            return dp[i][j] = false;
    }

    bool isMatch(string s, string p) {
        // return solve(s, p, s.length()-1, p.length()-1);
        vector<vector<int>> dp(s.length(), vector<int> (p.length(), -1));
        return solveMem(s, p, s.length()-1, p.length()-1, dp);
    }
};
class Solution {
public:
    bool solve(int index, string &s, vector<string>& wordDict){
        //base case
        if(index == s.length())
        return true;

        for(string &word: wordDict){
            int len = word.length();

            //match condition
            if(index + len <= s.length() && s.substr(index, len) == word){
                if(solve(index + len, s, wordDict))
                return true;
            }
            
        }
        return false;
    }

    //memoization
    bool solveMem(int index, string &s, vector<string>& wordDict, vector<int> &dp){
        //base case
        if(index == s.length())
        return true;

        if(dp[index] != -1)
        return dp[index];

        for(string &word: wordDict){
            int len = word.length();

            //match condition
            if(index + len <= s.length() && s.substr(index, len) == word){
                if(solveMem(index + len, s, wordDict, dp))
                return dp[index] = true;
            }
        }
        return dp[index] = false;
    }

    bool wordBreak(string s, vector<string>& wordDict) {
        // return solve(0, s, wordDict);
        vector<int> dp(s.length(), -1);
        return solveMem(0, s, wordDict, dp);
    }
};
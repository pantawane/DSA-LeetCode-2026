class Solution {
public:
    int solve(string &s, int index){
        //base case
        if(index == s.length())
        return 1;
        if(s[index] == '0')
        return 0;

        //one digit
        int oneDigit = solve(s, index + 1);
        //two digit number
        int twoDigit = 0;
        if(index+1 < s.length()){
            int num = (s[index] - '0')* 10 + (s[index+1] -'0');

            if(num >= 10 && num <= 26)
            twoDigit = solve(s, index+2);
        }
        return oneDigit + twoDigit;
    }
    //memoization
    int solveMem(string &s, int index, vector<int> &dp){
        //base case
        if(index == s.length())
        return 1;
        if(s[index] == '0')
        return 0;

        if(dp[index] != -1)
        return dp[index];

        //one digit
        int oneDigit = solveMem(s, index + 1, dp);
        //two digit number
        int twoDigit = 0;
        if(index+1 < s.length()){
            int num = (s[index] - '0')* 10 + (s[index+1] -'0');

            if(num >= 10 && num <= 26)
            twoDigit = solveMem(s, index+2, dp);
        }
        return dp[index] = oneDigit + twoDigit;
    }
    int numDecodings(string s) {
        // return solve(s, 0);
        vector<int> dp(s.length(), -1);
        return solveMem(s, 0, dp);
    }
};
class Solution {
public:
    bool solve(string &s, int index, int cnt, vector<vector<int>> &dp){
        int n = s.size();
        //base case
        if(cnt < 0) return false;
        if(index == n){
            if(cnt == 0){
                return true;
            }
            return false;
        }

        if(dp[index][cnt] != -1)
        return dp[index][cnt];

        if(s[index] == '('){
            return dp[index][cnt] = solve(s, index+1, cnt+1, dp);
        }else if(s[index] == ')'){
            return dp[index][cnt] = solve(s, index+1, cnt-1, dp);
        }else{
            return dp[index][cnt] = solve(s, index+1, cnt+1, dp)||
                   solve(s, index+1, cnt-1, dp)||
                   solve(s, index+1, cnt, dp);
        }
    }
    bool checkValidString(string s) {
        int n = s.size();
        vector<vector<int>> dp(n, vector<int> (n+1, -1));
        return solve(s, 0, 0, dp);
    }
};
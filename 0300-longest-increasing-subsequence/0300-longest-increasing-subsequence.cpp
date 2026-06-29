class Solution {
public:
    //recursion
    int solve(int n, vector<int>& nums, int curr, int prev){
        //base case
        if(curr == n)
        return 0;

        int include = 0;
        if(prev == -1 || nums[curr] > nums[prev])
        include = 1 + solve(n, nums, curr + 1, curr);

        int exclude = 0 + solve(n, nums, curr + 1, prev);

        return max(include, exclude);
    }
    //resursion + memoization
    int solveMem(int n, vector<int>& nums, int curr, int prev, vector<vector<int>> &dp){
        //base case
        if(curr == n)
        return 0;

        if(dp[curr][prev + 1] != -1)
        return dp[curr][prev + 1];

        int include = 0;
        if(prev == -1 || nums[curr] > nums[prev])
        include = 1 + solveMem(n, nums, curr + 1, curr, dp);

        int exclude = 0 + solveMem(n, nums, curr + 1, prev, dp);

        return dp[curr][prev + 1] = max(include, exclude);
    }

    //Tabulation
    int solveTab(int n, vector<int>& nums, int curr, int prev){

        vector<vector<int>> dp(n + 1, vector<int> (n+1, 0));

       for(curr = n-1; curr >=0; curr--){
        for(prev = n-1; prev >= -1; prev--){
            int include = 0;
    
            if(prev == -1 || nums[curr] > nums[prev])
            include = 1 + dp[curr + 1][curr + 1];

            int exclude = 0 + dp[curr+1][prev + 1];

           dp[curr][prev + 1] = max(include, exclude);
        }
       }
       return dp[0][0];
    }

    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        //return solve(n, nums, 0, -1);
        // vector<vector<int>> dp(n, vector<int> (n+1, -1));
        // return solveMem(n, nums, 0, -1, dp);
        return solveTab(n, nums, 0, -1);
    }
};
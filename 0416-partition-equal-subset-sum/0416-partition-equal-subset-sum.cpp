class Solution {
public:
    bool solve(int index, vector<int>& nums, int n, int target){
        if(index >= n)
        return false;
        if(target < 0)
        return false;
        if(target == 0)
        return true;

        int include = solve(index + 1, nums, n, target - nums[index]);
        int exclude = solve(index + 1, nums, n, target);

        return include || exclude;
    }

    bool solveMem(int index, vector<int>& nums, int n, int target, vector<vector<int>> &dp){
        if(index >= n)
        return false;
        if(target < 0)
        return false;
        if(target == 0)
        return true;

        if(dp[index][target] != -1)
        return dp[index][target];

        int include = solveMem(index + 1, nums, n, target - nums[index], dp);
        int exclude = solveMem(index + 1, nums, n, target, dp);

        return dp[index][target] = include || exclude;
    }

    bool canPartition(vector<int>& nums) {
        int n = nums.size();
        int total = 0;
        for(int i=0; i<n; i++){
            total += nums[i];
        }
        if(total & 1)
        return false;//odd case

        int target = total/2;

        vector<vector<int>> dp(n, vector<int> (target+1, -1));

        // return solve(0, nums, n, target);
        return solveMem(0, nums, n, target, dp);
    }
};
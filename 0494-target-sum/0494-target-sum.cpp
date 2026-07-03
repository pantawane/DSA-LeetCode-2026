class Solution {
public:
    //refer subset sum equal to k first
    int findWays(vector<int> &nums, int tar){

        int n = nums.size();
        vector<int> prev(tar + 1, 0), cur(tar+1, 0);
        if(nums[0] == 0) prev[0] = 2;
        else prev[0] = 1;
        //nums[0] = 0;
        if(nums[0] !=0 && nums[0] <= tar) prev[nums[0]] = 1;
        for(int ind = 1; ind< n; ind++){
            for(int sum =0; sum <= tar; sum++){
                int notTake = prev[sum];
                int take = 0;
                if(nums[ind] <= sum) take = prev[sum - nums[ind]];

                cur[sum] = (notTake + take);
            }
            prev = cur;
        }
        return prev[tar];
    }
    int countPartitions(int n, int d, vector<int>& nums){
        int totSum = 0;
        for(auto &it: nums) totSum += it;
        if(totSum - d < 0 || (totSum - d) % 2) return 0;
        return findWays(nums, (totSum - d) / 2);
    }

    int findTargetSumWays(vector<int>& nums, int target) {
         int n = nums.size();
         return countPartitions(n, target, nums);
    }
};
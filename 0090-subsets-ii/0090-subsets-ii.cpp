class Solution {
public:
    void solve(int index, vector<int> &nums, vector<vector<int>> &ans, vector<int> &output){

        ans.push_back(output);
        for(int i = index; i<nums.size(); i++){
            if(i > index && nums[i] == nums[i-1])
            continue;

            output.push_back(nums[i]);
            solve(i+1, nums, ans, output);
            output.pop_back();
        }
    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        
        vector<vector<int>> ans;
        vector<int> output;
        solve(0, nums, ans, output);
        return ans;
    }
};
class Solution {
public:
    void solve(int index, vector<int> &nums, vector<vector<int>> &ans, vector<int> &output){
        //base case
        if(index == nums.size()){
            ans.push_back(output);
            return;
        }

        //include
        output.push_back(nums[index]);
         solve(index+1, nums, ans, output);
        output.pop_back();

        //exclude
         solve(index+1, nums, ans, output);
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> output;
        solve(0, nums, ans, output);
        return ans;
    }
};
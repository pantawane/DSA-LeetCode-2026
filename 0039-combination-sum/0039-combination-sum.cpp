class Solution {
public:
    void solve(int index, vector<int>& candidates, vector<int> &output, vector<vector<int>> &ans, int target){
        //base case
        if(target == 0){
            ans.push_back(output);
            return;
        }
        if(index == candidates.size())
        return;

        if(target < 0)
        return;

        output.push_back(candidates[index]);
        //include
        // solve(index+1, candidates, output, ans, target-candidates[index]);
        //multiple includes
        solve(index, candidates, output, ans, target-candidates[index]);
        //backTrack
        output.pop_back();
        //exclude
        solve(index+1, candidates, output, ans, target);
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> ans;
        vector<int> output;

        solve(0, candidates, output, ans, target);
        return ans;
    }
};
class Solution {
public:
    void solve(int index, vector<int>& candidates,
               vector<int>& output,
               vector<vector<int>>& ans,
               int target) {

        if (target == 0) {
            ans.push_back(output);
            return;
        }

        for (int i = index; i < candidates.size(); i++) {

            // Skip duplicates
            if (i > index && candidates[i] == candidates[i - 1])
                continue;

            // Pruning
            if (candidates[i] > target)
                break;

            output.push_back(candidates[i]);

            solve(i + 1, candidates, output, ans,
                  target - candidates[i]);

            output.pop_back();
        }
    }

    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {

        sort(candidates.begin(), candidates.end());

        vector<vector<int>> ans;
        vector<int> output;

        solve(0, candidates, output, ans, target);

        return ans;
    }
};
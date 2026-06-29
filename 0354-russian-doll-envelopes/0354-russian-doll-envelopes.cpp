class Solution {
public:
    // Custom comparator
    static bool cmp(vector<int>& a, vector<int>& b) {
        if (a[0] == b[0])
            return a[1] > b[1];      // Same width -> height in descending order

        return a[0] < b[0];          // Width in ascending order
    }

    int maxEnvelopes(vector<vector<int>>& envelopes) {

        // Step 1: Sort
        sort(envelopes.begin(), envelopes.end(), cmp);

        // Step 2: Apply LIS on heights
        vector<int> ans;

        ans.push_back(envelopes[0][1]);

        for (int i = 1; i < envelopes.size(); i++) {

            int height = envelopes[i][1];

            if (height > ans.back()) {
                ans.push_back(height);
            }
            else {
                int index = lower_bound(ans.begin(), ans.end(), height) - ans.begin();
                ans[index] = height;
            }
        }

        return ans.size();
    }
};
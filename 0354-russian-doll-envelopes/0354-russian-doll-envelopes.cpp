class Solution {
public:
    static bool cmp(vector<int> &a, vector<int> &b){
        if(a[0] == b[0])
        return a[1] > b[1];  //same width- height decending order

        return a[0] < b[0];
    }

    int maxEnvelopes(vector<vector<int>>& envelopes) {
        //sort
        sort(envelopes.begin(), envelopes.end(), cmp);

        //using LIS on height only
        vector<int> ans;

        ans.push_back(envelopes[0][1]);
        for(int i=1; i<envelopes.size(); i++){
            int height = envelopes[i][1];

            if(height > ans.back())
            ans.push_back(height);
            else{
                int index = lower_bound(ans.begin(), ans.end(), height) - ans.begin();
                ans[index] = height;
            }
        }

       return ans.size();

    }
};
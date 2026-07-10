class Solution {
public:
    vector<int> partitionLabels(string s) {
        int n = s.size();
        //storing last occurences of each indexes
        unordered_map<char, int> lastIndex;

        for(int i=0; i<n; i++){
            lastIndex[s[i]] = i;
        }
        int start = 0;
        int end = 0;

        vector<int> ans;

        for(int i=0; i<n; i++){
            end = max(end, lastIndex[s[i]]);

            if(i == end){
                ans.push_back(end - start + 1);
                start = i+1;
            }
        }
        return ans;
    }
};
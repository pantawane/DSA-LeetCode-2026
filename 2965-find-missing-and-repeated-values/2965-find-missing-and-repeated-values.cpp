class Solution {
public:
    vector<int> findMissingAndRepeatedValues(vector<vector<int>>& grid) {

        
        unordered_map<int, int> mp;

        for(int i=0; i<grid.size(); i++){
            for(int j=0; j<grid[i].size(); j++){
               mp[grid[i][j]]++;
            }
        }

        int repeated = -1;
        int missing = -1;

        int n = grid.size();

        for (int i = 1; i <= n * n; i++) {
            if (mp.find(i) == mp.end()) {
                missing = i;
            } else if (mp[i] == 2) {
                repeated = i;
            }
        }

        return {repeated, missing};
    }
};
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_map<char, int> mp;
        int i = 0;
        int res = 0;

        for(int j =0; j<s.size(); j++){
            if(mp.find(s[j]) != mp.end()){
                i = max(mp[s[j]] + 1, i);
            }
            mp[s[j]] = j;
            res = max(res, j-i+1);
        }

        return res;
    }
};
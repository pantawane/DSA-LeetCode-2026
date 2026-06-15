class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_set<char> st;
        int i = 0;
        int ans = 0;

        for(int j = 0; j< s.size(); j++){
            //if duplicates exists, remove 1st elemnt
            while(st.count(s[j])){
                st.erase(s[i]);
                i++;
            }
            st.insert(s[j]);
            ans = max(ans, j-i+1);
        }
        return ans;
    }
};
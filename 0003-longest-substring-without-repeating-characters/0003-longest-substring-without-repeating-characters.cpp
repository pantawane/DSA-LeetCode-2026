class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n = s.size();
        int ans = 0;
        for(int i =0; i<n; i++){
            //create set
            unordered_set<char> st;
            for(int j=i; j<n; j++){
                if(st.count(s[j]))
                break;
                st.insert(s[j]);

                ans = max(ans, j-i+1);
            }
        }
        return ans;
    }
};
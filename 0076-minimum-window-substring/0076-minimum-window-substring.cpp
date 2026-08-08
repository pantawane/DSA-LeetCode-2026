class Solution {
public:
    string minWindow(string s, string t) {
        int n = s.size();
        int m = t.size();
        int startIdx = -1;
        int minLen = INT_MAX;
        int cnt = 0;
        int l=0, r=0;

        vector<int> hash(256, 0);

        for(char ch: t){
            hash[ch]++;
        }

        while(r < n){
            if(hash[s[r]] > 0){
                cnt = cnt + 1;
            }

            hash[s[r]]--;

            while(cnt == m){
                if(r-l+1 < minLen){
                    minLen = r-l+1;
                    startIdx = l;
                }

                hash[s[l]]++;
                if(hash[s[l]] > 0) {
                    cnt = cnt - 1;
                } 
                l = l + 1; 
            }
            r = r+1;
        }

        return startIdx == -1 ? "" : s.substr(startIdx, minLen);
    }
};
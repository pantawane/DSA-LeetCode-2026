class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {

        //base case
        if(s.empty() || g.empty())
        return 0;
        //suppose g = [1 5 3 3 4] ans s = [4 2 1 2 1 3]
        int n = g.size();  int m = s.size();
        sort(g.begin(), g.end());
        sort(s.begin(), s.end());
        //two pointer
        int l = 0;
        int r = 0;

        while(l < m && r < n){
            if(g[r] <= s[l]){
                r = r+1;
            }
            l = l+1;
        }
        return r;
    }
};
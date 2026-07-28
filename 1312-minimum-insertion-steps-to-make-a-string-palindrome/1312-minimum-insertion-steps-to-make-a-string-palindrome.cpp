class Solution {
public:
    int solveSpaOpt(string &a, string &b){

        vector<int> curr(b.length()+1, 0);
        vector<int> next(b.length()+1, 0);

        for(int i=a.length()-1; i>=0; i--){
            for(int j= b.length()-1; j>=0; j--){
            int ans = 0;
            if(a[i] == b[j]){
            ans = 1 + next[j+1];
            }else{
            ans = max(next[j], curr[j+1]);
        }
            curr[j] = ans;
            }
            next = curr;
        }
        return next[0];
    }

    int longestPalindromeSubseq(string s) {
        //same as longest common subsequesces just reverse the string and return the ans
        string revStr = s;
        reverse(revStr.begin(), revStr.end());
        int ans = solveSpaOpt(s, revStr);
        return ans;
    }
    int minInsertions(string s) {
        return s.size() - longestPalindromeSubseq(s);
    }
};
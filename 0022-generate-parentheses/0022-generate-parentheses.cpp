class Solution {
public:
    void solve(int open, int close, int n, string &temp, vector<string> &ans){
        //base case
        if(open == close && open == n){
            ans.push_back(temp);
            return;
        }
        //Add "(" parenthises 
        if(open < n){
            temp.push_back('(');
        solve(open+1, close, n, temp, ans);
        temp.pop_back();
        }  //backtrack

        //Add ")" parenthesis
        if(close < open){
            temp.push_back(')');
        solve(open, close+1, n, temp, ans);
        temp.pop_back(); //backtrack
        }
    }
    vector<string> generateParenthesis(int n) {
        vector<string> ans;
        string temp;

        solve(0, 0, n, temp, ans);
        return ans;
    }
};
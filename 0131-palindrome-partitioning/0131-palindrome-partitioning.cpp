class Solution {
public:
    bool isPalin(string &s){
        string s2 = s;
        reverse(s2.begin(), s2.end());
        return s2 == s;
    }
    void solve(string &s, vector<string> &partitions, vector<vector<string>> &ans){
        //base case
        if(s.size() == 0){
            ans.push_back(partitions);
            return;
        }
        for(int i=0; i<s.size(); i++){
            string part = s.substr(0, i+1);
            if(isPalin(part)){
                partitions.push_back(part);
                 string remaining = s.substr(i+1);
                 solve(remaining, partitions, ans);
                 partitions.pop_back();
            }
        }
    }

    vector<vector<string>> partition(string s) {
        vector<vector<string>> ans;
        vector<string> partitions;

        solve(s, partitions, ans);
        return ans;
    }
};
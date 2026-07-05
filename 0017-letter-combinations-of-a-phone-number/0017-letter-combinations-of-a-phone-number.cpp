class Solution {
public:
    void solve(string &digits, int index, string output, vector<string> &ans, string mapping[]){
        if(index == digits.length()){
            ans.push_back(output);
            return;
        }
        int number = digits[index] - '0';
        string value = mapping[number];
        for(int i=0; i<value.length(); i++){
            output.push_back(value[i]);
            solve(digits, index+1, output, ans, mapping);
            //backtrack
            output.pop_back();
        }
    }
    vector<string> letterCombinations(string digits) {
        vector<string> ans;
        string output;
        if(digits.length() == 0)
        return ans;

        //mapping keypad numbers to letters
        string mapping[10] = {"","","abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};
        solve(digits, 0, output, ans, mapping);
        return ans;
    }
};
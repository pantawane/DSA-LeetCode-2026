class Solution {
public:
    string multiply(string num1, string num2) {
        if(num1 == "0" || num2 == "0")
        return "0";

        int n = num1.size();
        int m = num2.size();

        vector<int> ans(n+m, 0);

        for(int i= n-1; i>=0; i--){
            for(int j= m-1; j>=0; j--){

                int mul = (num1[i] - '0') * (num2[j] - '0');
                int pos = (n - 1 - i) + (m - 1 - j);
                ans[pos] += mul;

                //carry
                int k = pos;
                while(ans[k] >= 10){
                    ans[k+1] += ans[k]/10;
                    ans[k] %= 10;
                    k++;
                }
            }
        }

        while(ans.size() > 1 && ans.back() == 0){
            ans.pop_back();
        }
        reverse(ans.begin(), ans.end());

        string res;
        for(int digit: ans){
            res.push_back(digit + '0');
        }

        return res;
    }
};
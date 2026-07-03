class Solution {
public:
    int solve(vector<int>& prices, int index, int buy){
        if(index == prices.size())
        return 0;
        int profit = 0;
        if(buy){
            profit = max( (-prices[index] + solve(prices, index+1, 0)), solve( prices, index+1, 1));
        }else{
            profit = max( (prices[index] + solve(prices, index+1, 1)), solve(prices, index+1, 0));
        }
        return profit;
    }
    //memoization
    int solveMem(vector<int>& prices, int index, int buy, vector<vector<int>> &dp){
        if(index == prices.size())
        return 0;
        if(dp[index][buy] != -1)
        return dp[index][buy];
        int profit = 0;
        if(buy){
            profit = max( (-prices[index] + solveMem(prices, index+1, 0, dp)), solveMem( prices, index+1, 1, dp));
        }else{
            profit = max( (prices[index] + solveMem(prices, index+1, 1, dp)), solveMem(prices, index+1, 0, dp));
        }
        return dp[index][buy] = profit;
    }
    //tabulation
    int solveTab(vector<int>& prices){
        int n = prices.size();

        vector<vector<int>> dp(prices.size()+1, vector<int> (2, 0));

        //dp[n-1][buy] = 0;
        for(int index = n-1; index >= 0; index--){
            for(int buy = 1; buy >=0; buy--){
                int profit = 0;
                if(buy){
                    profit = max( (-prices[index] + dp[index+1][0]), dp[index+1][1]);
                }else{
                    profit = max( (prices[index] + dp[index+1][1]), dp[index+1][0]);
                }
                dp[index][buy] = profit;
            }
        }
         return dp[0][1];
    }

    int maxProfit(vector<int>& prices) {
        return solveTab(prices);
        //vector<vector<int>> dp(prices.size(), vector<int> (2, -1));
        //return solveMem(prices, 0, 1, dp);
    }
};
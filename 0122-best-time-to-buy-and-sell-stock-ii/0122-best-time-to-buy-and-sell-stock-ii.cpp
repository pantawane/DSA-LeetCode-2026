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

    int maxProfit(vector<int>& prices) {
        
        vector<vector<int>> dp(prices.size(), vector<int> (2, -1));
        return solveMem(prices, 0, 1, dp);
    }
};
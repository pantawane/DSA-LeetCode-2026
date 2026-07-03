class Solution {
public:
    int solve(vector<int>& prices, int index, int buy, int limit){
        if(index == prices.size())
        return 0;
        if(limit == 0)
        return 0;
        int profit = 0;
        if(buy){
            profit = max( (-prices[index] + solve(prices, index+1, 0, limit)), solve( prices, index+1, 1, limit));
        }else{
            profit = max( (prices[index] + solve(prices, index+1, 1, limit-1)), solve(prices, index+1, 0, limit));
        }
        return profit;
    }

    int solveMem(vector<int>& prices, int index, int buy, int limit, vector<vector<vector<int>>> &dp){
        if(index == prices.size())
        return 0;
        if(limit == 0)
        return 0;
        if(dp[index][buy][limit] != -1)
        return dp[index][buy][limit];

        int profit = 0;
        if(buy){
            profit = max( (-prices[index] + solveMem(prices, index+1, 0, limit, dp)), solveMem( prices, index+1, 1, limit, dp));
        }else{
            profit = max( (prices[index] + solveMem(prices, index+1, 1, limit-1, dp)), solveMem(prices, index+1, 0, limit, dp));
        }
        return dp[index][buy][limit] = profit;
    }



    int maxProfit(vector<int>& prices) {
        //return solve(prices, 0, 1, 2);
        int n = prices.size();
        vector<vector<vector<int>>> dp(n, vector<vector<int>> (2, vector<int> (3, -1)));
        return solveMem(prices, 0, 1, 2, dp);
    }
};
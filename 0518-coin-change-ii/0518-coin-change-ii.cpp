class Solution {
public:
    int solve(int amount, vector<int>& coins, int index){
        //base case
        if(index == 0){
            if(amount % coins[0] == 0){
                return 1;
            }
            return 0;
        }

        //not take
        int notTake = solve(amount, coins, index -1);
        //take
        int take = 0;
        if(coins[index] <= amount){
            take = solve(amount-coins[index], coins, index);
        }
        return notTake + take;
    }

    //memoization
    int solveMem(int amount, vector<int>& coins, int index, vector<vector<int>> &dp){
        //base case
        if(index == 0){
            if(amount % coins[0] == 0){
                return 1;
            }
            return 0;
        }

        if(dp[index][amount] != -1)
        return dp[index][amount]; 

        //not take
        int notTake = solveMem(amount, coins, index -1, dp);
        //take
        int take = 0;
        if(coins[index] <= amount){
            take = solveMem(amount-coins[index], coins, index, dp);
        }
        return dp[index][amount] = notTake + take;
    }

    int change(int amount, vector<int>& coins) {
        int n = coins.size();
        // return solve(amount, coins, n-1);
        vector<vector<int>> dp(n, vector<int> (amount + 1, -1));
        return solveMem(amount, coins, n-1, dp);
    }
};
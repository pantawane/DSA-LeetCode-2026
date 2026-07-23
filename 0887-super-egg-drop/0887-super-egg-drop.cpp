// class Solution {
// public:
//     int solve(int k, int n, vector<vector<int>> &dp){
//         //base case
//         if(n==0 || n==1) return n;

//         if(k == 1) return n;

//         if(dp[k][n] != -1)
//         return dp[k][n];

//         int res = INT_MAX;
//         for(int i=1; i<=n; i++){
//             int curr = max(solve(k-1, i-1, dp), solve(k, n-i, dp));

//             if(curr < res)
//             res = curr;
//         }
//         return dp[k][n] = res + 1;
//     }

//     int solveTab(int k, int n){

//         vector<vector<int>> dp(k+1, vector<int> (n+1, 0));

//         for(int i =1; i<=k; i++){
//             for(int j=1; j<=n; j++){
//                 if(i == 1){
//                     dp[i][j] = j;
//                 }
//                 else if(j == 1){
//                     dp[i][j] = 1;
//                 }
//                 else{
//                     int res = INT_MAX;

//                     for(int mj = j-1, pj = 0; mj >=0; mj--, pj++){
//                         int v1 = dp[i][mj]; //survives
//                         int v2 = dp[i-1][pj]; //breaks

//                         int val = max(v1, v2);
//                         res = min(res, val);
//                     }
//                     dp[i][j] = res + 1;
//                 }
//             }
//         }
//         return dp[k][n];
//     }
//     int solveEgg(int k, int n){
//         vector<vector<long long>> dp(n + 1, vector<long long>(k + 1, 0));

//         int cnt = 0;

//         while(dp[cnt][k] < n){
//             cnt++;
//         }

//         for(int i=1; i<=k; i++){

//             dp[cnt][i] = 1 + dp[cnt-1][i-1] + dp[cnt-1][i];
//         }
//         return cnt;

//     }
//     int superEggDrop(int k, int n) {
//         // vector<vector<int>> dp(k+1, vector<int> (n+1, -1));
//         // return solve(k, n, dp);
//         return solveEgg(k, n);
//     }
// };

class Solution {
public:
    int superEggDrop(int k, int n) {

        vector<vector<long long>> dp(n + 1, vector<long long>(k + 1, 0));

        int moves = 0;

        while (dp[moves][k] < n) {

            moves++;

            for (int eggs = 1; eggs <= k; eggs++) {

                dp[moves][eggs] =
                    dp[moves - 1][eggs - 1] +
                    dp[moves - 1][eggs] +
                    1;
            }
        }

        return moves;
    }
};
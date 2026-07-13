class Solution {
public:
    int solve(int i, int amount, vector<int> &coins, vector<vector<int>> &dp) {
        if(i>=coins.size()) return 0;
        if(amount<0) return 0;
        if(amount == 0) return 1;
        if(dp[i][amount]!= -1) return dp[i][amount];
        return dp[i][amount] = solve(i, amount-coins[i], coins, dp) + solve(i+1, amount, coins, dp);
    }
    int change(int amount, vector<int>& coins) {
        vector<vector<int>> dp(coins.size()+1, vector<int>(amount+1, -1));
        return solve(0, amount, coins, dp);
    }
};

class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        vector<int> dp(amount+1, 1e9);
        dp[0] = 0;
        for(int currentAmount = 1; currentAmount <= amount; currentAmount++) {
            for(auto coin: coins) {
                if(coin <= currentAmount) {
                    dp[currentAmount] = min(dp[currentAmount], 1 + dp[currentAmount-coin]);
                }
            }
        }

        return dp[amount]<1e9?dp[amount]:-1;
    }
};

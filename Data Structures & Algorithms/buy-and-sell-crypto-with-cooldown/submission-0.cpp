class Solution {
public:
    int solve(int i, int value, vector<int> &prices, vector<vector<int>> &dp) {
        if(i>=prices.size()) return 0;
        if(dp[i][value+1] != -1) return dp[i][value+1];
        if(value!=-1) {
            return dp[i][value+1] = max(prices[i]-value + solve(i+2, -1, prices, dp), solve(i+1, value, prices, dp)); 
        }
        else {
            return dp[i][value+1] = max(solve(i+1, value, prices, dp), solve(i+1, prices[i], prices, dp));
        }
    }
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<vector<int>> dp(n+1, vector<int>(1002, -1));
        return solve(0, -1, prices, dp);
    }
};

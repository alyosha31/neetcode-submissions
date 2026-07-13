class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<int> post(n);
        post[n-1]= prices[n-1];
        for(int i = n-2; i >= 0; i--) {
            post[i] = max(post[i+1], prices[i+1]);
        }
        int profit = 0;
        for(int i = 0; i < prices.size(); i++) {
            profit=max(profit, post[i]-prices[i]);
        }
        return profit;
    }
};

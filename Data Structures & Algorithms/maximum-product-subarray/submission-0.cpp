class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int n = nums.size();
        if(n==1) return nums[0];
        vector<vector<int>> dp(n+1, vector<int>(n+1));
        int maxiProd = -1e9;
        for(int length = 1; length <= n; length++) {
            for(int l = 0; l+length-1<n; l++) {
                int r = l+length-1;
                if(length == 1) {
                    dp[l][r] = nums[l];
                }
                else {
                    dp[l][r] = dp[l][r-1]*nums[r];
                }
                maxiProd = max(maxiProd, dp[l][r]);
            }
        }
        return maxiProd;
    }
};

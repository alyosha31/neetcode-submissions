class Solution {
public:
    int solve(int left, int right, vector<int> &nums, vector<vector<int>> &dp) {
        // key intuition is to think in terms of last balloon burst in the interval because that will always be left*lastBalloon*right
        if(left>right) return 0;

        if(dp[left][right] != -1) return dp[left][right];
        int maxAns = 0;
        for(int i = left; i <= right; i++) {
            maxAns = max(maxAns, solve(left, i-1, nums, dp) + nums[left-1]*nums[i]*nums[right+1] + solve(i+1, right, nums, dp));
        }

        return dp[left][right] = maxAns;
    }
    int maxCoins(vector<int>& nums) {
        int n = nums.size();

        vector<int> balloons(n + 2, 1);

        for (int i = 0; i < n; i++) {
            balloons[i + 1] = nums[i];
        }

        vector<vector<int>> dp(
            n + 2,
            vector<int>(n + 2, -1)
        );

        return solve(1, n, balloons, dp);;
    }
};

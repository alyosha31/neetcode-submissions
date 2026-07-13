class Solution {
public:
    int solve(int i, int sum, int target, int total, vector<int> &nums, vector<vector<int>> &dp) {
        if(i>nums.size()) return 0;
        if(i==nums.size()) {
            if(target == sum) {
                return 1;
            }
            else return 0;
        }
        if(dp[i][(total)-sum] != -1) return dp[i][(total)-sum];
        return dp[i][(total)-sum] = solve(i+1, sum-nums[i], target, total, nums, dp) + solve(i+1, sum+nums[i], target, total, nums, dp);
    }
    int findTargetSumWays(vector<int>& nums, int target) {
        int total = 0;
        for(auto num: nums) total+=num;
        vector<vector<int>> dp(nums.size()+1, vector<int>(2*abs(total)+1, -1));
        return solve(0, 0, target, total, nums, dp);
    }
};

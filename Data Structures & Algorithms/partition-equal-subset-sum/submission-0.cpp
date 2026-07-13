class Solution {
public:
    bool solve(int i, int target, vector<int> &nums, vector<vector<int>> &dp) {
        if(i>=nums.size()) return false;
        if(target==0) return true;
        if(target<0) return false;
        if(dp[i][target] != -1) return dp[i][target];
        // skip
        bool skip = solve(i+1, target, nums, dp);
        // take
        bool take = solve(i+1, target-nums[i], nums, dp);

        return dp[i][target] = skip||take;
    }
    bool canPartition(vector<int>& nums) {
        int n = nums.size();
        int totalSum = 0;

        for(auto num:nums) totalSum+=num;

        if(totalSum%2) return false;

        int target= totalSum/2;

        vector<vector<int>> dp(n+1, vector<int>(target+1, -1));

        return solve(0, target, nums, dp);
    }
};

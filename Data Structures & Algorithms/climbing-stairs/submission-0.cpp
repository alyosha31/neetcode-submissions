class Solution {
public:
    int climbing(int i, int n, vector<int> &dp) {
        if(i>n) return 0;
        if(i == n) return 1;
        if(dp[i] != -1) return dp[i];
        return dp[i] = climbing(i+1, n, dp) + climbing(i+2, n, dp);
    }

    int climbStairs(int n) {
        vector<int> dp(n+1, -1);
        return climbing(0, n, dp);
    }
};

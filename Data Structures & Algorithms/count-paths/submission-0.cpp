class Solution {
public:
    int solve(int i, int j, int rows, int cols, vector<vector<int>> &dp) {
        if(i>=rows) return 0;
        if(j>=cols) return 0;
        if(i == rows-1 && j == cols-1) return 1;

        if(dp[i][j] != -1) return dp[i][j];

        return dp[i][j] = solve(i+1, j, rows, cols, dp) + solve(i, j+1, rows, cols, dp);
    }
    int uniquePaths(int m, int n) {
        vector<vector<int>> dp(m+1, vector<int>(n+1, -1));
        return solve(0, 0, m, n, dp);
    }
};

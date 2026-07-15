class Solution {
public:
    vector<pair<int, int>> moves = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
    int solve(int i, int j, vector<vector<int>> &matrix, vector<vector<int>> &dp) {
        if(i>=matrix.size() || i < 0) return 0;
        if(j>=matrix[0].size() || j < 0) return 0;
        
        int maxiSize = 1;
        if(dp[i][j]!= -1) return dp[i][j];

        for(int k = 0; k < moves.size(); k++) {
            int x = moves[k].first;
            int y = moves[k].second;

            int ii = i + x;
            int jj = j + y;
            if(ii >= 0 && ii < matrix.size() && jj >= 0 && jj < matrix[0].size() && matrix[ii][jj] > matrix[i][j]) {
                maxiSize = max(maxiSize, 1 + solve(ii, jj, matrix, dp));
            }
        }

        return dp[i][j] = maxiSize;
    }

    int longestIncreasingPath(vector<vector<int>>& matrix) {
        int n = matrix.size();
        int m = matrix[0].size();
        vector<vector<int>> dp(n+1, vector<int>(m+1, -1));
        int ans = 1;
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                ans = max(ans, solve(i, j, matrix, dp));
            }
        }
        return ans;
    }
};

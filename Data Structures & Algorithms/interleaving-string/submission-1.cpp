class Solution {
public:
    int solve(int i, int j, string s1, string s2, string s3, vector<vector<int>> &dp) {
        if(i == s1.size() && j == s2.size()) {
            return 1;
        }
        if(dp[i][j] != -1) return dp[i][j];
        int moves1 = 0;
        int moves2 = 0;
        if(i<s1.size()) {
            if(s1[i] == s3[i+j]) {
                moves1 = solve(i+1, j, s1, s2, s3, dp);
            }
        }
        if(j<s2.size()) {
            if(s2[j] == s3[i+j]) {
                moves2 = solve(i, j+1, s1, s2, s3, dp);
            }
        }

        return dp[i][j] = moves1||moves2;
    } 
    bool isInterleave(string s1, string s2, string s3) {
        int n = s1.size();
        int m = s2.size();
        if(n+m != s3.size()) return 0;
        vector<vector<int>> dp(n+1, vector<int>(m+1, -1));
        return solve(0, 0, s1, s2, s3, dp);
    }
};

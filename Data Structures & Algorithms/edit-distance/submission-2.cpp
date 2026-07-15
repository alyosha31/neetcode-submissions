class Solution {
public:
    int solve(int i, int j, string s1, string s2, vector<vector<int>> &dp) {
        if(j == s2.size()) {
            return (s1.size()-i);
        }
        if(i == s1.size()) {
            return s2.size()-j; // or -1e9?
        }
        if(dp[i][j] != -1) return dp[i][j];
        int ans = 0;
        if(s1[i] == s2[j]) {
            ans = solve(i+1, j+1, s1, s2, dp);
        }
        else {
            ans = 1 + min(solve(i+1, j+1, s1, s2, dp), solve(i+1, j, s1, s2, dp));
        }

        return dp[i][j] = ans;
    }
    int minDistance(string word1, string word2) {
        int n = word1.size();
        int m = word2.size();
        if(m>n) return minDistance(word2, word1);
        vector<vector<int>> dp(n+1, vector<int>(m+1, -1));  
        return solve(0, 0, word1, word2, dp);
    }
};

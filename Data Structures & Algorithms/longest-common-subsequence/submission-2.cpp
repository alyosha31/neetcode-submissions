class Solution {
public:
    int solve(int i, int j, string s1, string s2, vector<vector<int>> &dp) {
        if(i>=s1.size()) return 0;
        if(j>=s2.size()) return 0;
        if(i == s1.size()-1 && j==s2.size()-1) {
            if(s1[i] == s2[j]) return 1;
            else return 0;
        } 
        if(dp[i][j] != -1) return dp[i][j];
        if(s1[i] == s2[j]) {
            return dp[i][j] = max(1 + solve(i+1, j+1, s1, s2, dp), max(solve(i, j+1, s1, s2, dp), solve(i+1, j, s1, s2, dp)));
        }
        else {
            return dp[i][j] = max(solve(i+1, j, s1, s2, dp), max(solve(i, j+1, s1, s2, dp), solve(i+1, j+1, s1, s2, dp)));
        }
    }

    int longestCommonSubsequence(string text1, string text2) {
        vector<vector<int>> dp(text1.size()+1, vector<int>(text2.size()+1, -1));
        int ans = solve(0, 0, text1, text2, dp);
        if(ans < 0) return 0;
        else return ans;
    }
};

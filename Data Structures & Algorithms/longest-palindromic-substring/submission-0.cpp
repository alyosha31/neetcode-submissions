class Solution { 
public:
    string longestPalindrome(string s) {
        // interval dp where dp[l][r] = (s[l] == s[r]) && (dp[l+1][r-1])
        int n = s.size();
        vector<vector<int>> dp(n+1, vector<int>(n+1, 0));
        int maxLen = 1;
        int startInd = 0;
        for(int length = 1; length <= n; length++) {
            for(int l = 0; l + length - 1 < n; l++) {
                int r = l+length-1;
                if(length == 1) {
                    dp[l][r] = 1;
                }
                else if(length == 2) {
                    dp[l][r] = (s[l] == s[r]);
                }
                else dp[l][r] = (s[l] == s[r]) && dp[l+1][r-1];
                if(dp[l][r] && length > maxLen) {
                    maxLen = max(maxLen, length);
                    startInd = l;
                }
            }
        }
        return s.substr(startInd, maxLen);
    }
};

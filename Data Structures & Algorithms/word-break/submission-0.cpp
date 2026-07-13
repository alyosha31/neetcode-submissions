class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        int n = s.size();
        unordered_map<string, int> mp;
        for(auto it : wordDict) mp[it]++;
        vector<int> dp(n+1);
        dp[0] = 1;
        for(int i = 1; i <= n; i++) {
            for(int j = 0; j < i; j++) {
                if(dp[j] && mp.find(s.substr(j, i-j)) != mp.end()) {
                    dp[i] = 1;
                    break;
                }
            }
        }

        return dp[n];
    }
};

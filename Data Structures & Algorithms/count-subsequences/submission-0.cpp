class Solution {
public:
    int solve(int i, string &temp, string s, string t, vector<vector<int>> &dp) {
        if(temp == t) return 1;
        if(i>=s.size()) return 0;
        if(temp.size()> t.size()) return 0;
        int j = temp.size();
        if(dp[i][j] != -1) return dp[i][j];
        int sol = solve(i+1, temp, s, t, dp);
        temp.push_back(s[i]);
        if(s[i] == t[j])
        sol+= solve(i+1, temp, s, t, dp);
        temp.pop_back();

        return dp[i][j] = sol;
    }
    int numDistinct(string s, string t) {
        vector<vector<int>> dp(s.size()+1, vector<int>(t.size()+1, -1));
        string temp = "";
        return solve(0, temp, s, t, dp);
    }
};

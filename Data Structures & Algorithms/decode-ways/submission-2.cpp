class Solution {
public:
    int isValid(string t) {
        if(t.size()>2) return 0;
        if(stoi(t)>26) return 0;
        if(t[0] == '0') return 0;
        return 1;
    }
    int numDecodings(string s) {
        int n = s.size();
        vector<int> dp(n+1, 0);    
        if(s[0]=='0') return 0;
        if(s.size() == 1) return 1;
        dp[0] = 1; 
        dp[1] = (isValid(s.substr(0, 2))?1:0) + (s[1] == '0'?0:1);
        for(int i = 2; i < n; i++) {
            if(s[i] != '0') dp[i] += dp[i-1];
            if(isValid(s.substr(i-1, 2))) dp[i]+= dp[i-2];
        }
        return dp[n-1];
    }
};

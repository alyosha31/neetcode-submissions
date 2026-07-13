class Solution {
public:
    void dfs(int open, int close, int n, string &t, vector<string> &ans) {
        // stopping condition
        if(open>n) return;
        
        if(close == n) {
            ans.push_back(t);
            return;
        }

        // put an open
        t.push_back('(');
        dfs(open+1, close, n, t, ans);
        t.pop_back();
        // put a close
        if(open>close) {
            t.push_back(')');
            dfs(open, close+1, n, t, ans);
            t.pop_back();
        }
    }
    vector<string> generateParenthesis(int n) {
        string t = "";
        vector<string> ans;
        dfs(0, 0, n, t, ans);
        return ans;
    }
};

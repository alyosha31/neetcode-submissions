class Solution {
public:
    vector<string> code = {"", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
    void dfs(int start, string &t, string &digits, vector<string> &ans) {
        if(start == digits.size()) {
            ans.push_back(t);
            return;
        }
        string c = code[digits[start]-'0'];
        for(int i = 0; i < c.size(); i++) {
            t.push_back(c[i]);
            dfs(start+1, t, digits, ans);
            t.pop_back();
        }
        return;
    }

    vector<string> letterCombinations(string digits) {
        string t;
        vector<string> ans;
        if(!digits.size()) return ans;
        dfs(0, t, digits, ans);
        return ans;
    }
};

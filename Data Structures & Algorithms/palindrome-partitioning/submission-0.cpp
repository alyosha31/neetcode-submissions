class Solution {
public:
    bool isPal(string s) {
        int i = 0;
        int j = s.size()-1;
        while(i<j) {
            if(s[i] != s[j]) return false;
            i++;
            j--;
        }
        return true;
    }
    void dfs(int start, string &s, vector<string> &temp, vector<vector<string>> &ans) {
        //stopping conditions
        if(start == s.size()) {
            ans.push_back(temp);
            return;
        }
        string t = "";
        for(int i = start; i < s.size(); i++) {
            t.push_back(s[i]);
            if(!isPal(t)) continue;
            temp.push_back(t);
            dfs(i+1, s, temp, ans); 
            temp.pop_back();
        }
        return;
    }
    vector<vector<string>> partition(string s) {
        vector<string> temp;
        vector<vector<string>> ans;
        dfs(0, s, temp, ans);
        return ans;
    }
};

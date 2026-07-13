class Solution {
public:
    string foreignDictionary(vector<string>& words) {
        vector<int> indegree(26, -1);
        int countDistinct = 0;
        for(int i = 0; i < words.size(); i++) {
            for(int j = 0; j < words[i].size(); j++) {
                if(indegree[words[i][j]-'a'] == -1) {
                    indegree[words[i][j]-'a'] = 0;
                    countDistinct++;
                }
            }
        }
        vector<vector<int>> adj(26);
        for(int i = 0; i < words.size()-1; i++) {
            string a = words[i];
            string b = words[i+1];
            int len = min(a.size(), b.size());
            bool foundDifference = false;
            for(int j = 0; j < len; j++) {
                if(a[j] != b[j]) {
                    adj[a[j] - 'a'].push_back(b[j]-'a');
                    foundDifference = true;
                    break;
                }
            }
            if(!foundDifference && a.size() > b.size()) return "";
        }
        // topological sort using kahn's algorithm
        for(int i = 0; i < adj.size(); i++) {
            for(int j = 0; j < adj[i].size(); j++) {
                indegree[adj[i][j]]++;
            }
        }
        queue<int> q;
        for(int i = 0; i < indegree.size(); i++) {
            if(indegree[i] == 0) q.push(i);
        }
        string ans = "";
        while(!q.empty()) {
            int frnt = q.front();
            q.pop();
            ans.push_back('a' + frnt);
            for(auto it : adj[frnt]) {
                indegree[it]--;
                if(indegree[it] == 0) q.push(it);
            }
        }
        if(ans.size() != countDistinct) return ""; // cycle detection using kahn's algorithm
        return ans;
    }
};

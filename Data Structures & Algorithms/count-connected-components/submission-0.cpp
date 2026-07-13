class Solution {
public:
    void dfs(int element, vector<vector<int>> &v, vector<int> &vis) {
        if(vis[element]) return;
        vis[element] = 1;
        for(int i : v[element]) {
            dfs(i, v, vis);
        }
    }

    int countComponents(int n, vector<vector<int>>& edges) {
        vector<vector<int>> v(n);
        for(int i = 0; i < edges.size(); i++) {
            v[edges[i][0]].push_back(edges[i][1]);
            v[edges[i][1]].push_back(edges[i][0]);
        }
        vector<int> vis(n, 0);
        int count = 0;
        for(int i = 0; i < n; i++) {
            if(!vis[i]) {
                count++;
                dfs(i, v, vis);
            }
        }
        return count;
    }
};

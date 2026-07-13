class Solution {
public:
    bool isCycle(int element, int parent, vector<vector<int>> &v, vector<int> &vis, vector<int> &rec) {
        if(rec[element]) return true;
        if(vis[element]) return false;
        rec[element] = 1;
        vis[element] = 1;
        for(int i : v[element]) {
            if(i == parent) continue;
            if(isCycle(i, element, v, vis, rec)) {
                return true;
            }
        }
        rec[element] = 0;

        return false;
    }
    bool validTree(int n, vector<vector<int>>& edges) {
        //checks are : acyclic and connected
        // if they are connected, one dfs would resolve the entire thing
        vector<vector<int>> v(n);
        for(int i = 0; i < edges.size(); i++) {
            v[edges[i][0]].push_back(edges[i][1]);
            v[edges[i][1]].push_back(edges[i][0]);
        }
        vector<int> rec(n, 0);
        vector<int> vis(n, 0);
        int count = 0;
        for(int i = 0; i < n; i++) {
            if(vis[i]) continue;
            if(isCycle(i, -1, v, vis, rec)) {
                return false;
            }
            count++;
        }
        if(count>1) return false;
        return true;
    }
};

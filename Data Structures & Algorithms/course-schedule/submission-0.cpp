class Solution {
public:
    bool dfs(int element, vector<vector<int>> &v, vector<int> &recursion, vector<int> &vis) {
        if(recursion[element]) return true;
        if(vis[element]) return false;
        vis[element] = true;
        recursion[element] = true;
        for(int i : v[element]) {
            if(dfs(i, v, recursion, vis)) return true;
        }
        recursion[element] = false;
        return false;
    }
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> v(numCourses);
        for(int i = 0; i < prerequisites.size(); i++) {

            v[prerequisites[i][0]].push_back(prerequisites[i][1]);
        }
        vector<int> recursion(numCourses, 0);
        vector<int> vis(numCourses, 0);
        for(int i = 0; i < numCourses; i++) {
            if(!vis[i]){
                if(dfs(i, v, recursion, vis)) {
                    // cycle present
                    return false;
                }
            }
        }
        return true;
    }
};

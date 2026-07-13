class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        //topological sort
        vector<vector<int>> adj(numCourses);
        vector<int> indegree(numCourses, 0);
        for(int i = 0; i < prerequisites.size(); i++) {
            adj[prerequisites[i][1]].push_back(prerequisites[i][0]);
            indegree[prerequisites[i][0]]++;
        }
        // kahn's algorithm
        vector<int> ans;
        queue<int> q;
        for(int i = 0; i < indegree.size(); i++) {
            if(indegree[i] == 0) q.push(i);
        }
        while(!q.empty()) {
            int top = q.front();
            q.pop();
            ans.push_back(top);
            for(auto i : adj[top]) {
                indegree[i]--;
                if(indegree[i] == 0) q.push(i);
            }
        }
        if(ans.size() == numCourses) return ans;
        return vector<int> {};
    }
};

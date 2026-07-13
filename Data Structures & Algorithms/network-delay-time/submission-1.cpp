class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        // djikstra's algorithm 
        // creating an adjacency list
        vector<vector<pair<int, int>>> adj(n+1);
        for(int i = 0; i < times.size(); i++) {
            adj[times[i][0]].push_back(make_pair(times[i][1], times[i][2])); // u -> v, w
        }
        vector<int> dis(n+1, 1e9);
        dis[k] = 0;
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq; // min heap -> {weight, node} // sorting based on lowest weight
        pq.push(make_pair(0, k));
        while(!pq.empty()) {
            int node = pq.top().second;
            int weight = pq.top().first;
            pq.pop();
            for(auto it : adj[node]) {
                int neighbor = it.first;
                int weightToNeighbor = it.second;
                if(weightToNeighbor + weight < dis[neighbor]) {
                    dis[neighbor] = weightToNeighbor + weight;
                    pq.push(make_pair(weightToNeighbor + weight, neighbor));
                }
                
            }
        }
        int maxDistance = -1;
        for(int i = 1; i<=n; i++) {
            maxDistance = max(maxDistance, dis[i]);
        }
        return maxDistance==1e9?-1:maxDistance;
    }
};

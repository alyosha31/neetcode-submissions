class Solution {
public:
    int distance(vector<int> &p1, vector<int> p2) {
        return abs(p1[0]-p2[0]) + abs(p1[1] - p2[1]);
    }
    int minCostConnectPoints(vector<vector<int>>& points) {
        // prims algorithm for mst
        priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<pair<int, pair<int, int>>>> pq; //min heap -> edge weight, node, parent  
        int mstCost = 0;
        pq.push(make_pair(0, make_pair(0, -1))); 
        vector<int> vis(points.size(), 0);
        while(!pq.empty()) {
            auto top = pq.top();
            pq.pop();
            int node = top.second.first;
            int parent = top.second.second;
            int dist = top.first;
            if(vis[node] == 1) continue;
            vis[node] = 1;
            mstCost += dist;
            for(int i = 0; i < points.size(); i++) {
                if(i == node) continue;
                // else assume path and push into queue
                pq.push(make_pair(distance(points[i], points[node]), make_pair(i, node)));
            }
        }
        return mstCost;
    }
};

class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        vector<vector<pair<int, int>>> adj(n);
        for(int i = 0; i < flights.size(); i++) {
            adj[flights[i][0]].push_back({flights[i][1], flights[i][2]});
        }
        vector<vector<int>> dis(n, vector<int>(k+2, 1e9));
        priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<pair<int, pair<int, int>>>> pq; // {cost, {stops left, airport}}
        dis[src][k+1] = 0;
        pq.push({0, {k+1, src}});
        while(!pq.empty()) {
            auto top = pq.top();
            int cost = top.first;
            int hopsRemaining = top.second.first;
            int airport = top.second.second;
            pq.pop();
            if(hopsRemaining==0) continue;
            if(cost > dis[airport][hopsRemaining]) continue;
            for(auto it : adj[airport]) {
                int next = it.first;
                int cost2 = it.second;
                if(cost + cost2 < dis[next][hopsRemaining-1]) {
                    dis[next][hopsRemaining-1] = cost + cost2;
                    pq.push({cost+cost2, {hopsRemaining-1, next}});
                }
            }
        }
        int ans = 1e9;
        for(int i = 0; i < k+2; i++) {
            if(dis[dst][i] < ans) ans = dis[dst][i];
        }
        if(ans == 1e9) return -1;
        else return ans;
    }
};

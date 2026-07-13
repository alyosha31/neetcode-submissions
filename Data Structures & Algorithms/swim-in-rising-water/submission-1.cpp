class Solution {
public:
    int swimInWater(vector<vector<int>>& grid) {
        // djikstra's algorithm but modified
        priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<pair<int, pair<int, int>>>> pq; // max height so far, row and coordinate
        vector<vector<int>> vis(grid.size(), vector<int>(grid[0].size(), 0)); // visited array

        pq.push({grid[0][0], {0, 0}});
        int maxTracker = 0;

        vector<pair<int, int>> moves = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};

        while(!pq.empty()) {
            int row = pq.top().second.first;
            int col = pq.top().second.second;           
            int maxWeightOnThisPath = pq.top().first;
            pq.pop();
            if(vis[row][col]) continue;
            vis[row][col] = maxWeightOnThisPath;
            for(int i = 0; i < moves.size(); i++) {
                int x = row + moves[i].first;
                int y = col + moves[i].second;
                if(x<0 || x >= grid.size()) continue;
                if(y<0 || y >= grid[0].size()) continue;   
                if(vis[x][y]) continue;            
                pq.push({max(grid[x][y], maxWeightOnThisPath), {x, y}});
            }
        }
        return vis[grid.size()-1][grid.size()-1];
    }
};

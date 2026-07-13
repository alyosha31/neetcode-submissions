class Solution {
public:
    void islandsAndTreasure(vector<vector<int>>& grid) {
        queue<pair<int, int>> q; // multisource bfs
        for(int i = 0; i < grid.size(); i++) {
            for(int j = 0; j < grid[i].size(); j++) {
                if(grid[i][j] == 0) q.push({i, j});
            }
        }
        while(!q.empty()) {
            auto it = q.front();
            q.pop();
            int x = it.first;
            int y = it.second;
            if(x>0 && grid[x-1][y] == INT_MAX) {
                grid[x-1][y] = min(grid[x-1][y], grid[x][y] + 1);
                q.push({x-1, y});
            }
            if(x < grid.size()-1 && grid[x+1][y] == INT_MAX) {
                grid[x+1][y] = min(grid[x+1][y], grid[x][y] + 1);
                q.push({x+1, y});
            }
            if(y>0 && grid[x][y-1] == INT_MAX) {
                grid[x][y-1] = min(grid[x][y-1],grid[x][y] + 1);
                q.push({x, y-1});
            }
            if(y < grid[x].size()-1 && grid[x][y+1] == INT_MAX) {
                grid[x][y+1] = min(grid[x][y+1], grid[x][y] + 1);
                q.push({x, y+1});
            }
        }
    }
};

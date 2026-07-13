class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        vector<pair<int, int>> dirs =  {{1,0}, {-1, 0}, {0, 1}, {0, -1}};
        // multisource bfs where each level = 1 minute
        queue<pair<int, int>> q;
        for(int i = 0; i < grid.size(); i++) {
            for(int j = 0; j < grid[i].size(); j++) {
                if(grid[i][j] == 2) q.push({i, j});
            }
        }
        int minutes = 0;
        while(!q.empty()) {
            int size = q.size();
            for(int it = 0; it<size; it++) {
                auto front = q.front();
                q.pop();
                int x = front.first;
                int y = front.second;
                for(int i = 0; i < dirs.size(); i++) {
                    int xx = x + dirs[i].first;
                    int yy = y + dirs[i].second;
                    if(xx<0 || xx > grid.size()-1 || yy < 0 || yy > grid[xx].size()-1) continue;
                    if(grid[xx][yy] == 2 || grid[xx][yy] == 0) continue;
                    grid[xx][yy] = 2;
                    q.push({xx, yy});
                }
            }
            if(!q.empty())
            minutes++; 
        }
        int ans = minutes;
        for(int i = 0; i < grid.size(); i++) {
            for(int j = 0; j < grid[i].size(); j++) {
                if(grid[i][j] == 1) {
                    ans = -1;
                    break;
                }
            }
            if(ans == -1) break;
        }
        return ans;
    }
};

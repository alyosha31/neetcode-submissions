class Solution {
private: 
    int dfs(int i, int j, vector<vector<int>> &grid) {
        if(i<0 || i == grid.size()) return 0;
        if(j<0 || j == grid[i].size()) return 0;
        if(!grid[i][j] || grid[i][j] == -1) return 0;
        grid[i][j] = -1;
        return 1 + dfs(i+1, j, grid) + dfs(i, j+1, grid) + dfs(i-1, j, grid) + dfs(i, j-1, grid);
    }
public:
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int maxArea = 0;
        for(int i = 0; i < grid.size(); i++) {
            for(int j = 0; j < grid[i].size(); j++) {
                if(grid[i][j] == 1) {
                    maxArea = max(maxArea, dfs(i, j, grid));
                }
            }
        }
        return maxArea;
    }
};

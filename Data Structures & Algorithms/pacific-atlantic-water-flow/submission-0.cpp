class Solution {
public:
    void dfs(int i, int j, int check, int last, vector<vector<int>> &heights, vector<vector<int>> &v) {
        if(i<0 || i > heights.size()-1) return;
        if(j<0 || j > heights[i].size()-1) return;
        if(v[i][j] >= check) return;
        if(heights[i][j]<last) return;
        v[i][j]+=check;
        dfs(i+1, j, check, heights[i][j], heights, v);
        dfs(i-1, j, check, heights[i][j], heights, v);       
        dfs(i, j+1, check, heights[i][j], heights, v);
        dfs(i, j-1, check, heights[i][j], heights, v);
    }
    
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        vector<vector<int>> v(heights.size(), vector<int> (heights[0].size(), 0));
        for(int i = 0; i < heights.size(); i++) {
            int check = 1; // pacific
            if(v[i][0]<check) dfs(i, 0, check, -1, heights, v);
        }
        for(int j = 0; j < heights[0].size(); j++) {
            int check = 1; // pacific
            if(v[0][j]<check) dfs(0, j, check, -1, heights, v);
        }
        for(int i = 0; i < heights.size(); i++) {
            int check = 2; // atlantic
            int j = heights[0].size()-1;
            if(v[i][j]<check) dfs(i, j, check, -1, heights, v);
        }
        for(int j = 0; j < heights[0].size(); j++) {
            int check = 2; // atlantic
            int i = heights.size()-1;
            if(v[i][j]<check) dfs(i, j, check, -1, heights, v);
        }
        vector<vector<int>> ans;
        for(int i = 0; i < v.size(); i++) {
            for(int j = 0; j < v[0].size(); j++) {
                if(v[i][j]==3) {
                    ans.push_back(vector<int>{i, j});
                }
            }
        }
        return ans;
    }
};

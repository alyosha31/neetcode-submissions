class Solution {
public:
    void dfs(int start, vector<int> &nums, vector<int> &temp, vector<vector<int>> &ans) {
        ans.push_back(temp);
        for(int i = start; i < nums.size(); i++) {
            if(i>start && nums[i] == nums[i-1]) continue;
            temp.push_back(nums[i]);
            dfs(i+1, nums, temp, ans);
            temp.pop_back();
        }
    }

    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        // 1 2 1 -> 
        sort(nums.begin(), nums.end());
        vector<int> temp;
        vector<vector<int>> ans;
        dfs(0, nums, temp, ans);
        return ans;
    }
};

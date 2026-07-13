class Solution {
public:
    void dfs(vector<int>& nums, vector<int> &temp, vector<vector<int>> &ans, unordered_map<int, int> &mp) {
        if(temp.size() == nums.size()) {
            if(mp.size() == nums.size()) ans.push_back(temp);
            return;
        }
        if(temp.size() > nums.size()) return;
        for(int i = 0; i < nums.size(); i++) {
            if(mp.find(nums[i]) == mp.end()) {
                temp.push_back(nums[i]);
                mp[nums[i]]++;
                dfs(nums, temp, ans, mp);
                temp.pop_back();
                mp.erase(nums[i]);
            }
            else continue;
        }
    }
    vector<vector<int>> permute(vector<int>& nums) {
        vector<int> temp;
        vector<vector<int>> ans;
        unordered_map<int, int> mp;
        dfs(nums, temp, ans, mp);
        return ans;
    }
};

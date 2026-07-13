class Solution {
public:
    void make_subsets(int i, vector<int> temp, vector<int> &nums, set<vector<int>> &ans) {
        if(i==nums.size()) return;
        // skip the current element
        ans.insert(temp);
        make_subsets(i+1, temp, nums, ans);
        // take the current element
        temp.push_back(nums[i]);
        ans.insert(temp);
        make_subsets(i+1, temp, nums, ans);
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        set<vector<int>> ans;
        vector<int> temp;
        make_subsets(0, temp, nums, ans);
        vector<vector<int>> res;
        for(auto i : ans) {
            res.push_back(i);
        }
        return res;
    }
};

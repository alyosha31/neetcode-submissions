class Solution {
public:
    void make_subsets(int i, vector<int> &temp, vector<int> &nums, vector<vector<int>> &ans) {
        if(i==nums.size()) {
            ans.push_back(temp);
            return;
        }
        // skip the current element
        make_subsets(i+1, temp, nums, ans);
        // take the current element
        temp.push_back(nums[i]);
        make_subsets(i+1, temp, nums, ans);
        temp.pop_back();
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> temp;
        make_subsets(0, temp, nums, ans);
        return ans;
    }
};

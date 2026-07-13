class Solution {
public:
    void make_combo(int i, vector<int> &nums, int sum, int &target, vector<int> &temp, vector<vector<int>> &ans) {
        if(sum > target) return;
        if(i == nums.size()) {
            if(sum == target) {
                ans.push_back(temp);
            }
            return;
        }
        // move further up skipping
        make_combo(i+1, nums, sum, target, temp, ans);
        // consider and stay
        temp.push_back(nums[i]);
        make_combo(i, nums, sum+nums[i], target ,temp, ans);
        temp.pop_back();
    }
    vector<vector<int>> combinationSum(vector<int>& nums, int target) {
        vector<vector<int>> ans;
        vector<int> temp;
        int sum = 0;
        make_combo(0, nums, sum, target, temp, ans);
        return ans;
    }
};

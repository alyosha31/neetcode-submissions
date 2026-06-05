class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        vector<vector<int>> reps(nums.size(), vector<int>{});
        unordered_map<int, int> mp;
        for(int i = 0; i < nums.size(); i++) {
            mp[nums[i]]++;
        }
        for(auto it: mp) {
            reps[it.second-1].push_back(it.first);
        }
        vector<int> ans;
        for(int i = nums.size()-1; i>= 0 && k > 0; i--) {
            if(reps[i].size()){
                for(int j = 0; j < reps[i].size() && k; j++) {
                    k--;
                    ans.push_back(reps[i][j]);
                }
            }
        }
        return ans;
    }
};

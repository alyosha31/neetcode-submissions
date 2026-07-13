class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
       set<multiset<int>> ans;
       for(int i = 0; i < nums.size(); i++) {
        int target = -1*nums[i];
        unordered_set<int> s;
        for(int j = i+1; j < nums.size(); j++) {
            if(s.find(target-nums[j])!=s.end()) {
                ans.insert(multiset<int>{nums[i], nums[j], target-nums[j]});
            }
            s.insert(nums[j]);
        }
       }
       vector<vector<int>> ans2; 
       for(auto it : ans) {
        vector<int> temp;
        for(auto it2 : it) {
            temp.push_back(it2);
        }
        ans2.push_back(temp);
       }
       return ans2;
    }
};

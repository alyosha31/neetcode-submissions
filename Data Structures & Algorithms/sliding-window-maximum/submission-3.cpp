class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        map<int, int> mp;
        int i = 0;
        int j = 0;
        if(nums.size() == 1) return nums;
        vector<int> ans;
        while(j<nums.size()) {
            mp[nums[j]]++;
            if(j-i+1==k) {
                while(j<nums.size()) {
                    ans.push_back(mp.rbegin()->first);
                    mp[nums[i]]--;
                    if(!mp[nums[i]]) mp.erase(nums[i]);
                    i++;
                    j++;
                    if(j<nums.size())
                    mp[nums[j]]++;
                }
            }
            j++;
        } 
        return ans;
    }
};

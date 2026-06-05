class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
       unordered_map<int, int> hash;
       unordered_map<int, int> candidates;
       for(int i = 0; i < nums.size(); i++) {
        hash[nums[i]]++;
       }
       for(int i = 0; i < nums.size(); i++) {
        if(hash.find(nums[i]-1) == hash.end()) candidates[nums[i]]++;
       }
        int ans = 0;
        for(auto it: candidates) {
            int tracker = it.first;
            int temp_ans = 1;
            auto it2 = hash.begin();
            while(it2 != hash.end()) {
                it2 = hash.find(tracker+1);
                if(it2 != hash.end()) {
                    tracker++, temp_ans++;
                }
            }
            ans = max(ans, temp_ans);
        }
        return ans;
    }
};

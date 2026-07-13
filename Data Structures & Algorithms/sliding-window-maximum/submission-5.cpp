class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
       //using deque
       deque<int> dq;
       vector<int> ans;
       for(int i = 0; i < nums.size(); i++) {
        //make top fresh
        while(!dq.empty() && dq.front() <= i-k) {
            dq.pop_front();
        }
        //dominance rule
        while(!dq.empty() && nums[dq.back()] <= nums[i]) {
            dq.pop_back();
        }
        dq.push_back(i);
        if(i>=k-1) { //everytime after k-1, record an answer
            ans.push_back(nums[dq.front()]);
        }
       } 
       return ans;
    }
};

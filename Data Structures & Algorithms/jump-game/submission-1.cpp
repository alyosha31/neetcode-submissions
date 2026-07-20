class Solution {
public:
    bool canJump(vector<int>& nums) {
        int n = nums.size();
        if(n == 1) return 1;
        int index = n-1;
        int i = n-2;
        int ans = 0;
        while(true) {
            if(nums[i] >= index-i) {
                index = i;
            }
            if(index == 0) {
                ans = 1;
                break;
            }
            i--;
            if(i<0) {
                break;
            }
        }
        return ans;
    }
};

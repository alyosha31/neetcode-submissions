class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        // kadane's algorithm
        int res = nums[0];
        int maxSoFar = nums[0];
        for(int i = 1; i < nums.size(); i++) {
            maxSoFar = max(maxSoFar + nums[i], nums[i]);

            res = max(res, maxSoFar);
        }
        return res;
    }
};

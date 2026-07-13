class Solution {
public:
    int findMin(vector<int> &nums) {
        int r = nums.size()-1;
        int l = 0;
        while(l<r) {
            int mid = l + (r-l)/2;
            if(nums[mid] <= nums[r]) {
                if(nums[mid] <= nums[l]) r = mid;
                else r = mid-1;
            }
            else {
                l = mid+1;
            }
        }
        return nums[l];
    }
};

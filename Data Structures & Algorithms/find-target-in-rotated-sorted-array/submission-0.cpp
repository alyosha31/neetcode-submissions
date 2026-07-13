class Solution {
public:
    int binary_search(vector<int> &nums, int lower, int upper, int target) {
        int l = lower;
        int r = upper;
        while(l<=r) {
            int mid = l + (r-l)/2;
            if(nums[mid] == target) return mid;
            else if(nums[mid]>target) {
                r = mid-1;
            }
            else l = mid+1;
        }
        return -1;
    }
    int search(vector<int>& nums, int target) {
        //finding the smallest integer's index first
        int r = nums.size()-1;
        int l = 0;
        while(l<r) {
            int mid = l + (r-l)/2;
            if(nums[mid]<=nums[r]) {
                if(nums[mid]>nums[l]) {
                    r = mid-1;
                }
                else r=mid;
            }
            else {
                l = mid+1;
            }
        }
        int smallest_index = l;
        int first_search =  binary_search(nums, 0, l-1, target);
        int second_search = binary_search(nums, l, nums.size()-1, target);
        return first_search != -1?first_search:second_search;
    }
};

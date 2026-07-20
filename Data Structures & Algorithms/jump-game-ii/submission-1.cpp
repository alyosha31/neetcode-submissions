class Solution {
public:
    int jump(vector<int>& nums) {
        //gotta take care of three scenarios:
        // can it reach end directly? ans = 1;
        // can it reach minimum hops so far index? ans = minimumHop + 1;
        // can it reach current index? ans = currentInd + 1; 
        int n = nums.size();
        if(n == 1) return 0;
        vector<int> jumps(n, 0);
        int ans = 0;
        int miniHopInd = n-1;
        int index = n-1;
        int i = n-2;
        while(true) {
            // can it reach end
            if(nums[i] >= (n-1)-i) {
                jumps[i] = 1;
                miniHopInd = i;
                index = i;
            }
            else if(nums[i] >= (miniHopInd)-i) {
                jumps[i] = jumps[miniHopInd]+1;
                index = i;
            }
            else {
                int forward = nums[i];
                int forwardIndex = i+forward;
                jumps[i] = min(jumps[forwardIndex]+1, jumps[index] + 1);
                index = i;
            }
            i--;
            if(i < 0) {
                break;
            }
        }
        return jumps[0];
    }
};

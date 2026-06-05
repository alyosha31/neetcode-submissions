class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        vector<int> pre(nums.size()), post(nums.size());
        int mulpre = 1, mulpo = 1;
        pre[0] = 1, post[nums.size()-1]=1; 
        for(int i = 1; i < nums.size(); i++) {
            mulpre = mulpre*nums[i-1];
            mulpo = mulpo*nums[nums.size()-i];
            pre[i] = mulpre;
            post[nums.size()-i-1]=mulpo;
        }
        vector<int> ans;
        for(int i = 0; i < pre.size(); i++) {
            ans.push_back(pre[i]*post[i]);
        }
        return ans;
    }
};

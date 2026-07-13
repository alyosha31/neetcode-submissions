class Solution {
public:
    vector<int> twoSum(vector<int>& s, int target) {
        int i =0;
        int j = s.size()-1;
        while(i<j) {
            if(s[i] + s[j] == target) return vector<int>{i+1, j+1};
            else if(s[i]+s[j] < target) i++;
            else j--;
        }
        return vector<int>{};
    }
};

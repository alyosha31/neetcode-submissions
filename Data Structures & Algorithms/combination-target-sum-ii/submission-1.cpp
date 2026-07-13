class Solution {
public:
    void make_combo(int i, vector<int> &candidates, int sum, int &target, vector<int> &temp, vector<vector<int>> &ans) {
        if(sum > target) return;
        if(sum == target) {
            ans.push_back(temp);
            return;
        }
        if(i == candidates.size()) return;
        for(int it = i; it < candidates.size(); it++) {
            //skip same
            if(it>i && candidates[it] == candidates[it-1]) continue;
            //consider
            temp.push_back(candidates[it]);
            make_combo(it+1, candidates, sum+candidates[it], target, temp, ans);
            temp.pop_back();
        }
    }

    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end()); //sorting so we can skip same elements
        vector<vector<int>> ans;
        vector<int> temp;
        make_combo(0, candidates, 0, target, temp, ans);
        return ans;
    }
};

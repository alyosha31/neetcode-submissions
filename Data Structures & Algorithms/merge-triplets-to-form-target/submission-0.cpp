class Solution {
public:
    int isValid(vector<int> &a, vector<int> &b, int ind) {
        for(int i = 0; i < ind; i++) {
            if(a[i] < b[i]) return 0; 
        }
        return 1;
    }
    vector<int> maxOperation(vector<int> &a, vector<int> &b) {
        return vector<int> {max(a[0], b[0]), max(a[1], b[1]), max(a[2], b[2])};
    }
    bool mergeTriplets(vector<vector<int>>& triplets, vector<int>& target) {
        auto ans = triplets[0];
        int n = triplets.size();
        if(n == 1) return triplets[0] == target;
        for(int i = 0; i < n; i++) {
            if(target[0] == triplets[i][0]) {
                ans = triplets[i];
            }
        } // finding starting point
        for(int turn = 1; turn <= 2; turn++) {
            int toFind = target[turn];
            for(int i = 0; i < n; i++) {
                if(triplets[i][turn] == toFind && isValid(ans, triplets[i], turn)) {
                    ans = maxOperation(ans, triplets[i]);
                }
            }
        }
        return ans == target;
    }
};

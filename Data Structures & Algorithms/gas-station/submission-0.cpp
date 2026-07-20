class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int n = gas.size();
        vector<int> v(n);
        int sum = 0;
        for(int i = 0; i < n; i++) {
            v[i] = gas[i]-cost[i];
            sum += (v[i]);
        }
        if(sum<0) return -1;
        int ans = 0;
        sum = 0;
        for(int i = 0; i < n; i++) {
            sum += v[i];
            if(sum<0) {
                ans = i+1;
                sum = 0;
            }
        }
        return ans;
    }
};

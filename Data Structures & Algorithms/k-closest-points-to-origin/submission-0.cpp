class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        auto comp = [](const vector<int>&a, const vector<int>& b) {
            return (sqrt(a[0]*a[0] + a[1]*a[1])) < (sqrt(b[0]*b[0] + b[1]*b[1]));
        };
        priority_queue<vector<int>, vector<vector<int>>, decltype(comp)> pq(comp); 
        for(int i = 0; i < points.size(); i++) pq.push(points[i]);
        while(pq.size()>k) pq.pop();
        vector<vector<int>> ans;
        while(!pq.empty()) {
            ans.push_back(pq.top());
            pq.pop();
        }
        return ans;
    }
};

class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
       stack<pair<int, int>> st;
       int ans = heights[0];
       st.push(make_pair(heights[0], 0));
       for(int i = 1; i < heights.size(); i++) {
        int iterator = i;
        while(!st.empty() && st.top().first > heights[i]) {
            ans = max(ans, st.top().first*(i-st.top().second));
            iterator = st.top().second;
            st.pop();
        }
        st.push({heights[i], iterator});
       } 
       int fi = heights.size()-1;
       while(!st.empty()) {
        ans = max(ans, st.top().first*(fi-st.top().second+1));
        st.pop();
       }
       return ans;
    }
};

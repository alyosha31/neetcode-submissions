class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        stack<pair<int, int>> st;
        vector<int> ans(temperatures.size(), 0);
        st.push(make_pair(temperatures[0], 0));
        for(int i = 1; i < temperatures.size(); i++) {
            if(st.top().first<temperatures[i]) {
                while(!st.empty() && st.top().first < temperatures[i]) {
                    ans[st.top().second] = i-st.top().second;
                    cout<<"i: "<<i<<endl;
                    st.pop();
                } 
            }
            st.push(make_pair(temperatures[i], i));
        }
        
        return ans;
    }
};

class Solution {
public:

    bool willMeetBeforeTarget(pair<int, int> p1, pair<int, int> p2, int target) {
        if(p2.first*(p1.second - p2.second) + p2.second*(p2.first - p1.first) <= target*(p1.second - p2.second)) {
            cout<<"treuee"<<endl;
            return true;
        }
        cout<<"the fuck"<<endl;
        return false;
    }

    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        stack<pair<int, int>> st;
        vector<pair<int, int>> v(position.size());
        for(int i = 0; i < position.size(); i++) {
            v[i] = make_pair(position[i], speed[i]);
        }
        sort(v.begin(), v.end(), [](pair<int, int> a, pair<int, int>b) {
            return a.first>b.first;
        });
        st.push(v[0]);
        for(int i = 1; i < v.size(); i++) {
            if(willMeetBeforeTarget(v[i], st.top(), target)) {
                continue;
            }
            st.push(v[i]);
        }       
        return st.size(); 
    }
};

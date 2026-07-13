class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        priority_queue<int> pq;
        stack<int> s;
        unordered_map<int, int> mp;
        for(auto i : tasks) {
            mp[i]++;
        }
        for(auto i : mp) {
            pq.push(i.second);
        }
        int count = 0;
        while(!pq.empty()) {
            int cycles = n+1;
            while(!pq.empty() && cycles) {
                cycles--;
                int top = pq.top();
                pq.pop();
                top--;
                if(top) s.push(top);
                count++;
            }
            while(!s.empty() && cycles--) count++;
            while(!s.empty()) {
                pq.push(s.top());
                s.pop();
            }
        }
        return count;
    }
};

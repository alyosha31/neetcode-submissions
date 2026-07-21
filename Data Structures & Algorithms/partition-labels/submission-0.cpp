class Solution {
public:
    vector<int> partitionLabels(string s) {
        unordered_map<char, int> mp;
        int n = s.size();
        for(int i = 0; i < n; i++) {
            mp[s[i]]++;
        }
        unordered_map<char, int> curr;
        vector<int> ans;
        int size = 0;
        for(int i = 0; i < n; i++) {
            size++;
            mp[s[i]]--;
            curr[s[i]]++;
            if(mp[s[i]] == 0) {
                mp.erase(s[i]);
                curr.erase(s[i]);
                if(curr.size() == 0) {
                    ans.push_back(size);
                    size = 0;
                }
            }
        }
        return ans;
    }
};

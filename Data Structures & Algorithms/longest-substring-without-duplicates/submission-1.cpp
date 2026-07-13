class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int i = 0; 
        int j = 0;
        int n = s.size();
        int ans = 0;
        unordered_map<int, int> mp;
        while(j<s.size()) {
            while(j<s.size() && mp.find(s[j]) == mp.end()) {
                mp[s[j]]++;
                j++;
                ans = max(ans, j-i);    
            }
            if(mp.find(s[j]) != mp.end()) {
                while(i<j && mp.find(s[j]) != mp.end()){
                    mp[s[i]]--;
                    if(!mp[s[i]]) mp.erase(s[i]);
                    i++;
                }
                ans = max(ans, j-i);
            }
        }
        return ans;
    }
};

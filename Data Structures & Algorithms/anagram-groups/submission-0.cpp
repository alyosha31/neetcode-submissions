class Solution {
public:

    map<vector<int>, vector<int>> checkAnagrams(vector<vector<int>> &v) {
        map<vector<int>, vector<int>> mp;
       for(int i = 0; i < v.size(); i++) {
        mp[v[i]].push_back(i);
       }
       return mp; 
    }

    vector<vector<string>> groupAnagrams(vector<string>& strs) {
       vector<vector<int>> v(strs.size(), vector<int>(26, 0)); // m length vector for checking
       vector<vector<string>> ans;
       for(int i = 0; i < strs.size(); i++) {
        for(int j = 0; j < strs[i].size(); j++) {
            v[i][strs[i][j]-'a']++;
        }
       } 
       map<vector<int>, vector<int>> mp = checkAnagrams(v);
       for(auto it : mp) {
        vector<string> temp;
        for(int i = 0; i < it.second.size(); i++) {
            temp.push_back(strs[it.second[i]]);
        }
        ans.push_back(temp);
       }
       return ans;
    }
};

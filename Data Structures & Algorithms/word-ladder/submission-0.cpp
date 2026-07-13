class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        // idea is to change every letter with all of english letters one by one, and checking if it exists in the list of words
        // if it does exist in the list of words, then we push that in a queue
        queue<pair<string, int>> q;
        unordered_map<string, int> mp;
        for(int i = 0; i < wordList.size(); i++) mp[wordList[i]]++;
        q.push(make_pair(beginWord, 1));
        int ans = 0;
        while(!q.empty()) {
            string word = q.front().first;
            int level = q.front().second;
            if(word == endWord) {
                ans = level;
                break;
            }
            q.pop();
            for(int i = 0; i < word.size(); i++) {
                string temp = word;
                for(int j = 0; j < 26; j++) {
                    temp[i] = 'a' + j;
                    if(mp.find(temp) != mp.end()) {
                        q.push(make_pair(temp, level+1));
                        mp[temp]--;
                        if(mp[temp] == 0) mp.erase(temp);
                    }
                }
            }
        }
        return ans;
    }
};

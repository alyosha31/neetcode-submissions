class Solution {
public:
    int freqMaxOccuring(vector<int>&v) {
        int maxi = 0;
        for(int i = 0; i < 26; i++) {
            maxi = max(maxi, v[i]);
        }
        return maxi;
    }
    int characterReplacement(string s, int k) {
        int i = 0;
        int j = 0;
        int count=0;
        int ans = 0;
        vector<int>v(26, 0);
        while(j<s.size()) {
            v[s[j]-'A']++;
            count++;
            if(count-freqMaxOccuring(v)<=k) {
                ans = max(ans, count);
                j++;
            }
            else {
                while(i<=j && count-freqMaxOccuring(v)>k) {
                    v[s[i]-'A']--;
                    count--;
                    i++;
                }
                j++;
            }
        }
        return ans;
    }
};

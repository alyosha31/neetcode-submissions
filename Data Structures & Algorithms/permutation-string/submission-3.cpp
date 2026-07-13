class Solution {
public:
    bool isSubset(vector<int> v1, vector<int> v2) {
        for(int i = 0; i < 26; i++) {
            if(v1[i]-v2[i]<0) return false;
        }
        return true;
    }
    
    bool checkInclusion(string s1, string s2) {
       if(s1.size()>s2.size()) checkInclusion(s2, s1); 
       vector<int> v1(26, 0), v2(26, 0);
       for(int i = 0; i < s1.size(); i++) v1[s1[i]-'a']++;
       int i = 0;
       int j = 0;
       while(j<s2.size()) {
        v2[s2[j]-'a']++;
        if(isSubset(v1, v2)) {
            cout<<"j: "<<j<<"i: "<<i<<endl;
            if(j-i+1 == s1.size()) return true;
            j++;
        }
        else {
            cout<<"here"<<endl;
            while(i<=j && !isSubset(v1, v2)) {
                v2[s2[i]-'a']--;
                i++;
            }
            if(j-i+1 == s1.size()) return true;
            if(i>j) j=i;
            else j++;
        }
       }
       return false;
    }
};

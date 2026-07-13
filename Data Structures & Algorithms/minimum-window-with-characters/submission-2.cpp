class Solution {
public:

    bool isValid(vector<int> vs, vector<int> vt) {
        for(int i = 0; i < vs.size(); i++) {
            if(vs[i]-vt[i]<0) return false;
        }
        return true;
    }

    vector<int> formHash(string s) {
        vector<int> vs(60, 0);
        for(int i = 0; i < s.size(); i++) vs[s[i]-'A']++; 
        return vs;
    }

    string formSubstring(string s, int left, int right) {
        string temp="";
        for(int i = left; i <= right && i < s.size(); i++) {
            temp.push_back(s[i]);
        }
        return temp;
    }

    string minWindow(string s, string t) {
       vector<int> vs(60, 0), vt(60, 0); //hash arrays
       if(t.size()>s.size()) return "";
       for(int i = 0; i < t.size(); i++) vt[t[i]-'A']++; 
       string ans = s;
       // going left first 
       int i = 0;
       int j = s.size()-1;
       while(i<=j && i >=0 && j <= s.size()-1) {
        if(isValid(formHash(formSubstring(s, i, j)), vt)) {
            string temp = formSubstring(s, i, j);
            if(ans.size()>temp.size()) {
                ans = temp;
            }
            i++;
        }
        else { 
            i--;
            j--;
            while(i<=j && isValid(formHash(formSubstring(s, i, j)), vt)) {
                string temp = formSubstring(s, i, j);
                if(ans.size()>temp.size()) {
                    ans = temp;
                }
                j--;
            }
        }
       }
       i = 0;
       j = s.size()-1;
       while(i<j && i >=0 && j <= s.size()-1) {
        if(isValid(formHash(formSubstring(s, i, j)), vt)) {
            string temp = formSubstring(s, i, j);
            if(ans.size()>temp.size()) {
                ans = temp;
            }
            j--;
        }
        else { 
            j++;
            i++;
            while(i<j && isValid(formHash(formSubstring(s, i, j)), vt)) {
                string temp = formSubstring(s, i, j);
                if(ans.size()>temp.size()) {
                    ans = temp;
                }
                i++;
            }
        }
       }  
       if(isValid(formHash(ans), vt)) return ans; 
       else return "";
    }
};

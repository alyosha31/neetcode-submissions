class Solution {
public:
    string sanitizeString(string s) {
        string final = ""; 
        for(int i = 0; i < s.size(); i++) {
            if(isalnum(s[i])) {
                final.push_back(tolower(s[i]));
            }
        }
        return final;
    }

    bool isPalindrome(string s) {
        int i = 0;
        s = sanitizeString(s);
        int j = s.size()-1;
        while(i<j) {
            if(s[i] != s[j]) return false;
            i++;
            j--;
        }
        return true;
    }
};

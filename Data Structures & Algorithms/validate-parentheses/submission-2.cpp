class Solution {
public:
    bool isOpening(char c) {
        if(c == '(' or c == '{' or c == '[') {
            return true;
        }
        else return false;
    }
    bool isValid(string s) {
        stack<char> st;
        unordered_map<char, char> mp;
        mp['}'] = '{';
        mp[')'] = '(';
        mp[']'] = '[';
        if(s.size()%2) return false;
        for(int i = 0; i < s.size(); i++) {
            if(isOpening(s[i])) st.push(s[i]);
            else {
                if(!st.empty() && st.top() == mp[s[i]]) {
                    st.pop();
                } else {
                    return false;
                } 
            }
        }   
        if(st.empty())
        return true;
        
        return false;
    }
};

class Solution {
public:
    bool checkValidString(string s) {
        stack<int> opening; 
        stack<int> ast;
        for(int i = 0; i < s.size(); i++) {
            if(s[i] == '(') {
                opening.push(i);
            }
            if(s[i] == ')') {
                if(opening.empty()) {
                    if(ast.empty()) {
                        return 0;
                    }
                    else ast.pop();
                }
                else {
                    opening.pop();
                }
            }
            if(s[i] == '*') {
                ast.push(i);
            }
        }
        while(!opening.empty()) {
            if(ast.empty()) {
                return 0;
            }
            if(ast.top() < opening.top()) {
                return 0;
            }
            ast.pop();
            opening.pop();
        }
        return 1;
    }
};

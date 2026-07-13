class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> st;
        for(int i = 0; i < tokens.size(); i++) {
            if(tokens[i] == "+" or tokens[i] == "-" or tokens[i] == "/" or tokens[i] == "*") {
                int a = st.top();
                st.pop();
                int b = st.top();
                st.pop();
                int result = 0;
                if (tokens[i] == "+") {
    result = b + a;
}
else if (tokens[i] == "-") {
    result = b - a;
}
else if (tokens[i] == "*") {
    result = b * a;
}
else if (tokens[i] == "/") {
    result = b / a;
}
                st.push(result);
            }
            else st.push(stoi(tokens[i]));
        }
        return st.top();
    }
};

class MinStack {
public:
    vector<int> v;
    int iterator ;
    stack<int> st;
    MinStack() {
       v  = vector<int>{}; 
       iterator = -1;
       st.push(INT_MAX);
    }
    
    void push(int val) {
        v.push_back(val);
        iterator++;
        if(!st.empty() && val<=st.top()) {
            st.push(val);
        }
    }
    
    void pop() {
        if(iterator == -1) return;
        int val = v[iterator];
        v.pop_back();
        iterator--; 
        if(st.top() == val) {
            st.pop();
        }
    }
    
    int top() {
        return v[iterator];
    }
    
    int getMin() {
       return st.top(); 
    }
};

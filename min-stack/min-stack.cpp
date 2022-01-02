class MinStack {
public:
    stack<int> s;
    stack<int> min_val;
    MinStack() {
        
    }
    
    void push(int val) {
        if(min_val.empty() || val<=min_val.top())
            min_val.push(val);
        s.push(val);
    }
    
    void pop() {
        if(min_val.top()==s.top())
            min_val.pop();
        s.pop();
    }
    
    int top() {
        return s.top();
    }
    
    int getMin() {
        return min_val.top();
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */
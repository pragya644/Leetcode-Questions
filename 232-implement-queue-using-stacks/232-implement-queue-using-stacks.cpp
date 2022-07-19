class MyQueue {
public:
    stack<int> original;
    stack<int> helper;
    
    MyQueue() {
        
    }
    
    void push(int x) {
        while(original.empty()==false){
            helper.push(original.top());
            original.pop();
        }
        original.push(x);
        while(helper.empty()==false){
            original.push(helper.top());
            helper.pop();
        }
        
    }
    
    int pop() {
        int x = original.top();
        original.pop();
        return x;
    }
    
    int peek() {
        return original.top();
    }
    
    bool empty() {
        return original.empty();
    }
};

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue* obj = new MyQueue();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->empty();
 */
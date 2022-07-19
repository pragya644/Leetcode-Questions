class MyStack {
public:
    queue<int> q1;
    queue<int> q2;
    int curr;
    
    MyStack() {
        
    }
    
    void push(int x) {
        if(q1.empty()){
            q2.push(x);
        }else{
            q1.push(x);
        }
    }
    
    int pop() {
        if(!q1.empty()){
            int x;
            while(q1.empty()==false){
                x = q1.front();
                q1.pop();
                if(q1.empty())
                    return x;
                q2.push(x);
            }
        }else if(!q2.empty()){
            while(q2.empty()==false){
                int x = q2.front();
                q2.pop();
                if(q2.empty())
                    return x;
                q1.push(x);
            }
        }
        return -1;
    }
    
    int top() {
        if(!q1.empty()){
            int x;
            while(q1.empty()==false){
                x = q1.front();
                q1.pop();
                q2.push(x);
            }
            return x;
        }else if (!q2.empty()){
            int x;
            while(q2.empty()==false){
                x = q2.front();
                q2.pop();
                q1.push(x);
            }
            return x;
        }
        return -1;
    }
    
    bool empty() {
        if(q1.empty() && q2.empty())
            return true;
        return false;
    }
};

/**
 * Your MyStack object will be instantiated and called as such:
 * MyStack* obj = new MyStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->top();
 * bool param_4 = obj->empty();
 */
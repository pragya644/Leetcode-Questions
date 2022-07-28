class StockSpanner {
public:
    
    stack<pair<int,int>> s;
    
    StockSpanner() {
        
    }
    
    int next(int price) {
        if(s.empty()){
            s.push({price,1});
            return 1;
        }
        int nextValue = 0;
        while(!s.empty() && s.top().first<=price){
            auto curr = s.top();
            s.pop();
            nextValue += curr.second;
        }
        nextValue += 1;
        s.push({price,nextValue});
        return nextValue;
    }
};

/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner* obj = new StockSpanner();
 * int param_1 = obj->next(price);
 */
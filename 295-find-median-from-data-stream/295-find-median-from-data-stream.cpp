class MedianFinder {
public:
    
    //we can have one more value in minValue but can not have less value than maxValue
    
    priority_queue<int> minValue; //maxheap
    priority_queue<int,vector<int>, greater<int>> maxValue; //minheap
    
    MedianFinder() {
        
    }
    
    void addNum(int num) {
        minValue.push(num);
        maxValue.push(minValue.top());
        minValue.pop();   
        if(minValue.size()<maxValue.size()) 
        {
            minValue.push(maxValue.top());
            maxValue.pop();
        }
    }
    
    double findMedian() {
        if(minValue.size()>maxValue.size())
            return minValue.top();
        return double(minValue.top()+maxValue.top())/2;
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */
class KthLargest {
public:
    
    priority_queue<int> maxi;
    priority_queue<int,vector<int>, greater<int>> mini;
    int idx ;
    
    KthLargest(int k, vector<int>& nums) {
        idx = k;
        for(auto x: nums)
        {
            mini.push(x);
            if(mini.size()>k)
            {
                maxi.push(mini.top());
                mini.pop();
            }
        }
    }
    
    int add(int val) {
        mini.push(val);
        if(mini.size()>idx)
        {
            maxi.push(mini.top());
            mini.pop();
        }
        return mini.top();
    }
};

/**
 * Your KthLargest object will be instantiated and called as such:
 * KthLargest* obj = new KthLargest(k, nums);
 * int param_1 = obj->add(val);
 */
class SmallestInfiniteSet {
public:
    
    unordered_set<int> notPresent;
    
    SmallestInfiniteSet() {
        
    }
    
    int popSmallest() {
        int i=1;
        while(true)
        {
            if(notPresent.find(i)==notPresent.end()){
                notPresent.insert(i);
                return i;
            }
            i++;
        }
    }
    
    void addBack(int num) {
        if(notPresent.find(num)==notPresent.end())
        {
            return;
        }
        notPresent.erase(num);
    }
};

/**
 * Your SmallestInfiniteSet object will be instantiated and called as such:
 * SmallestInfiniteSet* obj = new SmallestInfiniteSet();
 * int param_1 = obj->popSmallest();
 * obj->addBack(num);
 */
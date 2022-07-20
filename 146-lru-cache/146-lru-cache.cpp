class LRUCache {
public:
    
    //we can not use remove because it take O(n) time;
    
    list<int> l;
    unordered_map<int,int> m;
    unordered_map<int,list<int>::iterator> add;
    int cap;
    
    LRUCache(int capacity) {
        cap = capacity;
    }
    
    int get(int key) {
        if(m.find(key)==m.end())
            return -1;
        list<int>::iterator it = add[key];
        l.erase(it);
        l.push_front(key);
        add[key] = l.begin();
        return m[key];
    }
    
    void put(int key, int value) {
        if(m.find(key)!=m.end()){
            
            m[key] = value;
            list<int>::iterator it = add[key];
            l.erase(it);
            l.push_front(key);
            add[key] = l.begin();
            return;
            
        }
        if(m.size()==cap){
                int least = l.back();
                l.pop_back();
                m.erase(least);
                add.erase(key);
            
        }
        m[key] = value;
        l.push_front(key);
        add[key] = l.begin();
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */
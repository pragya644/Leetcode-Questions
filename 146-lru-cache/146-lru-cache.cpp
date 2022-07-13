class LRUCache {
public:
    
    list<pair<int,int>> l;
    unordered_map<int,list<pair<int,int>>::iterator> m;
    int cap;
    
    LRUCache(int capacity) {
        cap = capacity;
    }
    
    int get(int key) {
        if(m.find(key)!=m.end())
        {
            l.splice(l.begin(),l,m[key]);
            auto temp = m[key];
            return temp->second;
        }
        return -1;
    }
    
    void put(int key, int value) {
        if(m.find(key)!=m.end())
        {
            l.splice(l.begin(), l, m[key]);
            auto temp = m[key];
            temp->second = value;
            return;
        }
        if(m.size()==cap)
        {
            auto temp = l.back();
            auto val = temp.first;
            l.pop_back();
            m.erase(val);
        }
        l.push_front({key,value});
        m[key] = l.begin();
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */
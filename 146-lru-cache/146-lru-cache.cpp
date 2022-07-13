class LRUCache {
public:
    
    unordered_map<int,int> m; // key value pair store;
    list<int> l;  //recent used key into linkedi
    unordered_map<int,list<int>::iterator> add; //storing address of key
    int cap;
    
    LRUCache(int capacity) {
       cap = capacity; 
    }
    
    int get(int key) {
        if(m.find(key)==m.end())
            return -1;
        list<int>::iterator curr = add[key];
        l.erase(curr);
        l.push_front(key);
        add[key] = l.begin(); //bcoz now key list address is in begining of list
        return m[key];
    }
    
    void put(int key, int value) {
        if(m.find(key)!=m.end()) //if key is already present than change the value
        {
            m[key] = value; 
            list<int>::iterator curr = add[key]; //key position
            l.erase(curr);  
            l.push_front(key);
            add[key] = l.begin();
            return;
        }
        if(m.size()==cap)
        {
            int key = l.back();
            l.pop_back();
            m.erase(key);
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
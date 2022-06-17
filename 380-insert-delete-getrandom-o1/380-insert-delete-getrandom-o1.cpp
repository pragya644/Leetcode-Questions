class RandomizedSet {
public:
    unordered_map<int,int> s;
    vector<int> v;
    RandomizedSet() {
        
    }
    
    bool insert(int val) {
        if(s.find(val)!=s.end())
            return false;
        v.push_back(val);
        s[val] = v.size()-1;
        return true;
    }
    
    bool remove(int val) {
        if(s.find(val)==s.end())
            return false;
        int last = v[v.size()-1];
        s[last] = s[val];
        v[s[val]] = last;
        v.pop_back();
        s.erase(val);
        return true;
    }
    
    int getRandom() {
       return v[rand() % v.size()]; 
    }
};

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet* obj = new RandomizedSet();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */
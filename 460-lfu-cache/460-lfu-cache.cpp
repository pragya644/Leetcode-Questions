class LFUCache {
public:
    
    unordered_map<int,list<int>> diffFreq;
    unordered_map<int,pair<int,int>> keyValueFreq;
    unordered_map<int,list<int>::iterator> keyAddress;
    int cap;
    int currMinFreq = 1;
    
    
    void update(int key){
        int prevfreq = keyValueFreq[key].second ; 
        int freq = prevfreq+1;                 //freq increased by 1
        keyValueFreq[key].second = freq;       // update the freq
        diffFreq[prevfreq].erase(keyAddress[key]);
        
        if(diffFreq[currMinFreq].size()==0){
            diffFreq.erase(currMinFreq);
            currMinFreq += 1;
        }
        
        diffFreq[freq].push_front(key);
        keyAddress[key] = diffFreq[freq].begin();
    }
    
    LFUCache(int capacity) {
        cap = capacity;
    }
    
    int get(int key) {
        if(!keyValueFreq.count(key))
            return -1;
        
        update(key);
        
        return keyValueFreq[key].first;
    }
    
    void put(int key, int value) {
        if(keyValueFreq.count(key)){
            
            update(key);
            
            keyValueFreq[key].first = value;
            return;
        }
        if(keyValueFreq.size() >= cap){
            
            if(keyValueFreq.size()==0)
                return;
            
            int leastFreqUsedKey = diffFreq[currMinFreq].back();
            diffFreq[currMinFreq].pop_back();
            keyValueFreq.erase(leastFreqUsedKey);
            keyAddress.erase(leastFreqUsedKey);
            if(diffFreq[currMinFreq].size()==0)
                diffFreq.erase(currMinFreq);
            
        }
        
        keyValueFreq[key] = {value,1};
        diffFreq[1].push_front(key);
        keyAddress[key] = diffFreq[1].begin();
        currMinFreq = 1;
        
    }
};

/**
 * Your LFUCache object will be instantiated and called as such:
 * LFUCache* obj = new LFUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */
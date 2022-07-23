class NumberContainers {
public:
    
    unordered_map<int,int> m;
    unordered_map<int,set<int>> s;
    
    NumberContainers() {
        
    }
    
    void change(int i, int num) {
        if(m.find(i)!=m.end()){
            
            int prev = m[i];
            auto it = s[prev].find(i);
            s[prev].erase(it);
            m[i] = num;
            if(s.find(num)!=s.end() && s[num].size()!=0){
                s[num].insert(i);
            }else{
                set<int> t;
                t.insert(i);
                s[num] = t;
            }
            
        }else{
            
            m[i] = num;
            if(s.find(num)!=s.end() && s[num].size()!=0){
                s[num].insert(i);
            }else{
                set<int> t;
                t.insert(i);
                s[num] = t;
            }
            
        }
    }
    
    int find(int num) {
        if(s.find(num)!=s.end() && s[num].size()!=0)
            return *(s[num].begin());
        return -1;
    }
};

/**
 * Your NumberContainers object will be instantiated and called as such:
 * NumberContainers* obj = new NumberContainers();
 * obj->change(index,number);
 * int param_2 = obj->find(number);
 */
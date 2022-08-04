class Solution {
public:
    string reorganizeString(string s) {
        unordered_map<int,int> m;
        for(auto c: s){
            m[c]++;
        }
        priority_queue<pair<int,int>> pq;
        for(auto x: m){
            pq.push({x.second,x.first});
        }
        string res = "";
        while(pq.empty()==false){
            auto top1 = pq.top();
            pq.pop();
            res += top1.second;
            if(!pq.empty()){
                auto top2 = pq.top();
                pq.pop();
                res += top2.second;
                int count = top2.first-1;
                if(count>0){
                    pq.push({count,top2.second});
                }
            }
            int count = top1.first-1;
            if(count>0){
                pq.push({count,top1.second});
            }
        }
        for(int i=0; i<res.size()-1; i++){
            if(res[i]==res[i+1])
                return "";
        }
        return res;
    }
};
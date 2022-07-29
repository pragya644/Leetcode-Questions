class Solution {
public:
    vector<string> findAndReplacePattern(vector<string>& words, string pattern) {
        vector<string> ans;
        for(auto x: words){
            
            if(pattern.length()!=x.length())
                continue;
            
            int len = x.length();
            unordered_map<char,char> m;
            unordered_set<char> vis;
            bool flag = true;
            
            for(int i=0; i<len; i++){
                if(m.find(pattern[i])==m.end()){
                    if(vis.find(x[i])!=vis.end()){
                        flag = false;
                        break;
                    }
                    m[pattern[i]] = x[i];
                    vis.insert(x[i]);
                }else{
                    if(m[pattern[i]]!=x[i]){
                        flag = false;
                        break;
                    }
                }
            }
            if(flag)
                ans.push_back(x);
            
        }
        return ans;
    }
};
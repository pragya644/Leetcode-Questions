class Solution {
public:
    bool isAnagram(string s, string t) {
        if(s.length()!=t.length())
            return false;
        unordered_map<char,int> m;
        for(auto x: s){
            m[x]++;
        }
        for(auto x: t){
            m[x]--;
        }
        for(auto x: m){
            if(x.second!=0)
                return false;
        }
        return true;
    }
};
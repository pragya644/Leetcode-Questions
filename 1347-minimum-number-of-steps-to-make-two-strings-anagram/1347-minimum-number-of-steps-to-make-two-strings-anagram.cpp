class Solution {
public:
    int minSteps(string s, string t) {
        map<char,int> m;
        int ans = 0;
        for(int i=0; i<s.length(); i++)
            m[s[i]]++;
        for(int i=0; i<t.length(); i++)
        {
            auto it = m.find(t[i]);
            if(it!=m.end() && it->second>0)
                m[t[i]]--;
        }
        for(auto x: m)
            ans += x.second;
        return ans;
    }
};
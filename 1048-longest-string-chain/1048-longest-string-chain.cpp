class Solution {
public:
    static bool comp(string &s1, string &s2)
    {
        return s1.length()<s2.length();
    }
    
    int longestStrChain(vector<string>& words) {
        int n = words.size();
        sort(words.begin(), words.end(), comp);
        unordered_map<string,int> m;
        int res = 0;
        for(auto w: words)
        {
            for(int i=0; i<w.length(); i++)
            {
                string prev = w.substr(0,i)+w.substr(i+1);
                m[w] = max(m[w], m.find(prev)!=m.end() ? m[prev]+1 : 1);
            }
            res = max(res,m[w]);
        }
        return res;
    }
};
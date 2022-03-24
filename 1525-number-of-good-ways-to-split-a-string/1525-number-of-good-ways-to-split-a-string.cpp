class Solution {
public:
    int numSplits(string s) {
        int n = s.length();
        int ans = 0;
        unordered_map<char,int> l;
        unordered_map<char,int> r;
        l[s[0]]++;
        for(int i=1; i<n; i++)
            r[s[i]]++;
        if(l.size()==r.size())
            ans++;
        for(int i=1; i<n; i++)
        {
            l[s[i]]++;
            r[s[i]]--;
            if(r[s[i]]==0)
                r.erase(s[i]);
            if(l.size()==r.size())
                ans++;
        }
        return ans;
    }
};
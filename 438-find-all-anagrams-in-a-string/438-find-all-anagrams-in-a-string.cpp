class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        vector<int> res;
        int len_s = s.length();
        int len_p = p.length();
        if(len_s<len_p)
            return {};
        unordered_map<char,int> mp;
        unordered_map<char,int> ms;
        int check = 0;
        for(int i=0; i<len_p; i++)
            mp[p[i]]++;
        int len = mp.size();
        for(int i=0; i<len_p; i++)
        {
            ms[s[i]]++;
            if(ms[s[i]]==mp[s[i]])
                check++;
        }
        if(check == len)
            res.push_back(0);
        
        for(int i=0; i<=len_s-len_p; i++)
        {
            int idx = i+len_p;
            ms[s[idx]]++;
            if(mp[s[idx]]==ms[s[idx]])
                check++;
            if(mp[s[i]]==ms[s[i]])
                check--;
            ms[s[i]]--;
            if(check==len)
                res.push_back(i+1);
        }
        return res;
    }
};
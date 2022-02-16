class Solution {
public:
    
    bool solve(vector<int> &s1, vector<int> &s2)
    {
        int diff = 0;
        for(int i=25; i>=0; i--)
        {
            diff += s1[i] - s2[i];
            if(diff<0)
                return false;
        }
        return true;
    }
    
    vector<int> countfreq(string s)
    {
        vector<int> v(26,0);
        for(int i=0; i<s.length(); i++)
        {
            v[s[i]-'a']++;
        }
        return v;
    }
    
    bool checkIfCanBreak(string s1, string s2) {
        auto freq1 = countfreq(s1);
        auto freq2 = countfreq(s2);
        return solve(freq1, freq2) || solve(freq2, freq1);
    }
};
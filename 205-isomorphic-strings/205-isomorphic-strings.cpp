class Solution {
public:
    bool isIsomorphic(string s, string t) {
        unordered_map<char,char> m;
        unordered_set<char> st;
        for(int i=0; i<s.length(); i++)
        {
            if(m.find(s[i])!=m.end())
            {
                if(m[s[i]]!=t[i])
                    return false;
            }
            else if(st.find(t[i])==st.end())
            {
                m[s[i]] = t[i];
                st.insert(t[i]);
            }
            else
                return false;
        }
        return true;
    }
};
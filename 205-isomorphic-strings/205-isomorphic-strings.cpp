class Solution {
public:
    bool isIsomorphic(string s, string t) {
        vector<char> first_string(256,0);
        vector<char> second_string(256,0);
        for(int i=0; i<s.length(); i++)
        {
            if(first_string[s[i]]==0 && second_string[t[i]]==0)
            {
                first_string[s[i]] = t[i];
                second_string[t[i]] = s[i];
            }
            else if(first_string[s[i]]!=t[i])
                return false;
        }
        return true;
    }
};
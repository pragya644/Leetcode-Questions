class Solution {
public:
    bool backspaceCompare(string s, string t) {
        int k = 0;
        for(int i=0; i<s.length(); i++)
        {
            if(s[i]=='#')
            {
                k--;
                k = max(k,0);
            }
            else
            {
                s[k] = s[i];
                k++;
            }
        }
        int l = 0;
        for(int i=0; i<t.length(); i++)
        {
            if(t[i]=='#')
            {
                l--;
                l = max(l,0);
            }
            else
            {
                t[l] = t[i];
                l++;
            }
        }
        if(l!=k)
            return false;
        for(int i=0; i<k; i++)
        {
            if(s[i]!=t[i])
                return false;
        }
        return true;
    }
};
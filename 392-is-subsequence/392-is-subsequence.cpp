class Solution {
public:
    bool isSubsequence(string s, string t) {
        int n = s.length();
        int r = n-1;
        int m = t.length();
        int i = m-1;
        while(r>=0 && i>=0)
        {
            if(s[r]==t[i])
            {
                r--;
            }
            i--;
        }
        if(r<0)
            return true;
        return false;
    }
};
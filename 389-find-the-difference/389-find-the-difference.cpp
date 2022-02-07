class Solution {
public:
    char findTheDifference(string s, string t) {
        sort(s.begin(),s.end());
        sort(t.begin(),t.end());
        int lens = s.length()-1;
        int lent = t.length()-1;
        while(lens>=0 && lent>=0)
        {
            if(s[lens]!=t[lent])
                return t[lent];
            lens--;
            lent--;
        }
        return t[0];
    }
};
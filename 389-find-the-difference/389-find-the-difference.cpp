class Solution {
public:
    char findTheDifference(string s, string t) {
        char r = 0;
        for(int i=0; i<s.length(); i++)
            r = r^s[i];
        for(int i=0; i<t.length(); i++)
            r = r^t[i];
        return r;
    }
};
class Solution {
public:
    int removePalindromeSub(string s) {
       if(s.length()==0)
           return 0;
        string temp = s;
        reverse(s.begin(), s.end());
        if(temp==s)
            return 1;
        return 2;
    }
};
class Solution {
public:
    int num(char r)
    {
        if(r=='I')
            return 1;
        if(r=='V')
            return 5;
        if(r=='X')
            return 10;
        if(r=='L')
            return 50;
        if(r=='C')
            return 100;
        if(r=='D')
            return 500;
        if(r=='M')
            return 1000;
        return -1;
    }
    int romanToInt(string s) {
        int n = s.length();
        int ans = num(s[n-1]);
        for(int i=n-2; i>=0; i--)
        {
            if(num(s[i])<num(s[i+1]))
                ans = ans-num(s[i]);
            else
                ans = ans+ num(s[i]);
        }
        return ans;
    }
};
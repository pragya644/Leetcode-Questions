class Solution {
public:
    
    int romanVal(char x){
        if(x=='I')
            return 1;
        if(x=='V')
            return 5;
        if(x=='X')
            return 10;
        if(x=='L')
            return 50;
        if(x=='C')
            return 100;
        if(x=='D')
            return 500;
        if(x=='M')
            return 1000;
        return 0;
    }
    
    int romanToInt(string s) {
        int ans = 0;
        int n = s.length();
        int i=0;
        while(i<n){
            int val1 = romanVal(s[i]);
            if(i<n-1){
                int val2 = romanVal(s[i+1]);
                if(val2>val1){
                    ans = ans + (val2-val1);
                    i += 2;
                    continue;
                }
            }
            ans += val1;
            i++;
        }
        return ans;
    }
};
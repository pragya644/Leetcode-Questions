class Solution {
public:
    bool isPalindrome(int x) {
        if(x<0)
            return false;
        long int ans = 0;
        long int n;
        int temp = x;
        while(x>0)
        {
            n = x%10;
            ans = ans*10 + n;
            x = x/10;
        }
        x = temp;
        if(x==ans)
            return true;
        return false;
    }
};
class Solution {
public:
    bool validPalindrome(string s) {
        int i = 0;
        int j = s.length()-1;
        int count1 = 0;
        int count2 = 0;
        while(i<=j)
        {
            if(s[i]==s[j])
            {
                i++;
                j--;
            }
            else
            {
                j--;
                count2++;
            }
        }
        
         i = 0;
         j = s.length()-1;
        while(i<=j)
        {
            if(s[i]==s[j])
            {
                i++;
                j--;
            }
            else
            {
                i++;
                count1++;
            }
        }
        if(count1 == 1 || count2==1 || count1 == 0 || count2==0)
             return true;
        return false;
    }
};
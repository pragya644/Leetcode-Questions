class Solution {
public:
    bool isSubsequence(string s, string t) {
        int len1 = s.length();
        int len2 = t.length();
        int i = 0, j=0;
        int count1 = 0;
        while(i<len1 && j<len2)
        {
            if(s[i]==t[j])
            {
                i++;
                j++;
                count1++;
            }
            else
                j++;
        }
        if(count1==len1)
            return true;
        return false;
    }
};
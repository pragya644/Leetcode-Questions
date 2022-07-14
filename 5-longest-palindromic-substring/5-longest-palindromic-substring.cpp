class Solution {
public:
    string longestPalindrome(string s) {
        int len = s.length();
        string ans = "";
        for(int i=0; i<len; i++)
        {
            int l = i, r = i;
            while(l>=0 && r<len && s[l]==s[r])
            {
                int tempLen = r-l+1;
                if(tempLen>ans.length())
                {
                    ans = s.substr(l,tempLen);
                }
                r++;
                l--;
            }
        }
        for(int i=0; i<len; i++)
        {
            int l = i, r = i+1;
            while(l>=0 && r<len && s[l]==s[r])
            {
                int tempLen = r-l+1;
                if(tempLen>ans.length())
                {
                    ans = s.substr(l,tempLen);
                }
                r++;
                l--;
            }
        }
        return ans;
    }
};
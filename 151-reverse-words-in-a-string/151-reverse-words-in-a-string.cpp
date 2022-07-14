class Solution {
public:
    string reverseWords(string s) {
        reverse(s.begin(),s.end());
        string ans= "";
        int len = s.length();
        int i=0;
        while(true)
        {
            while(s[i]==' ')
                i++;
            if(i==len)
                break;
            int l=i,r=i;
            while(i<len && s[i]!=' ')
            {
                r++;
                i++;
            }
            string temp = s.substr(l,r-l);
            reverse(temp.begin(),temp.end());
            ans = ans+temp+' ';
        }
        ans.pop_back();
        return ans;
    }
};
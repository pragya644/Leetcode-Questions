class Solution {
public:
    int countSubstrings(string s, string t) {
        int n = s.length();
        int m = t.length();
        int ans = 0;
        for(int i=0; i<n; i++)
        {
            for(int j=0; j<m; j++)
            {
                int diff = 0;
                for(int k=0; k<min((n-i), (m-j)); k++)
                {
                    if(s[k+i]!=t[k+j])
                        diff++;
                    if(diff>1)
                        break;
                    ans += diff;
                }
            }
        }
        return ans;
    }
};
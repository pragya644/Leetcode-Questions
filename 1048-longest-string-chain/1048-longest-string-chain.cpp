class Solution {
public:
    bool lcs(string &s1, string &s2)
    {
        if(s1.length()!=s2.length()+1)
            return false;
        int n = s1.length();
        int m = s2.length();
        int dp[n+1][m+1];
        for(int i=0; i<=n; i++)
        {
            for(int j=0; j<=m; j++)
            {
                if(i==0 ||j==0)
                    dp[i][j] = 0;
                else
                {
                    if(s1[i-1]==s2[j-1])
                        dp[i][j] = 1+dp[i-1][j-1];
                    else
                        dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
                }
            }
        }
        if(dp[n][m] == m)
            return true;
        return false;
    }
    
    static bool comp(const string &s1,const string &s2){
        return s1.length() < s2.length();
    }
    
    int longestStrChain(vector<string>& words) {
        int n = words.size();
        sort(words.begin(), words.end(), comp);
        vector<int>dp(n,1);
        int res = 1;
        for(int i=0; i<n; i++)
        {
            for(int j=0; j<i; j++)
            {
                if(lcs(words[i], words[j]) && dp[i]<dp[j]+1)
                    dp[i] = dp[j]+1;
            }
            res = max(dp[i], res);
        }
        return res;
    }
};
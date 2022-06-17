class Solution {
public:
    int numSquares(int n) {
        vector<int> v;
        for(int i=0; i<n; i++)
        {
            if(i*i<=n)
                v.push_back(i);
            else
                break;
        }
        int len = v.size();
        int dp[len+1][n+1];
        for(int i=0; i<=len; i++)
        {
            for(int j=0; j<=n; j++)
            {
                if(i==0)
                    dp[i][j] = INT_MAX-1;
                else if(j==0)
                    dp[i][j] = 0;
                else if(i==1)
                    dp[i][j] = j;
                else
                {
                    int x = v[i-1]*v[i-1];
                    if(x<= j)
                    {
                        dp[i][j] = min(1+dp[i][j-x], dp[i-1][j]);
                    }
                    else
                        dp[i][j] = dp[i-1][j];
                }
            }
        }
        return dp[len][n];
    }
};
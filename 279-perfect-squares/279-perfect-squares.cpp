class Solution {
public:
    int numSquares(int n) {
        vector<int> dp(n+1, INT_MAX);
        dp[0] = 0;
        int x = 1;
        while(x*x<=n)
        {
            for(int i=0; i<=n; i++)
            {
                if(x*x<=i)
                    dp[i] = min(1+dp[i-x*x], dp[i]);
            }
            x++;
        }
        return dp[n];
    }
};
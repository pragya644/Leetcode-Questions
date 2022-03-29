class Solution {
public:
//     int solve(int n, int dp[])
//     {
//         if(n==0 || n==1)
//             return n;
//         if(dp[n]!=-1)
//             return dp[n];
//         dp[n] = solve(n-2, dp)+solve(n-1, dp);
//         return dp[n];
//     }
    
//     int fib(int n) {
//         int dp[n+1];
//         memset(dp,-1,n);
//         return solve(n,dp);
//     }
     
    
      int fib(int n)
      {
          if(n<=1)
              return n;
          int dp[n+1];
          dp[0] = 0;
          dp[1] = 1;
          for(int i=2; i<=n; i++)
          {
              dp[i] = dp[i-1]+dp[i-2];
          }
          return dp[n];
      }
};
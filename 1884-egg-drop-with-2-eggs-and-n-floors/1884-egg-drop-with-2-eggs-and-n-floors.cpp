class Solution {
public:
    int dp[3][1001];
    
    int solve(int egg, int f)
    {
        if(f==0 || f==1)
            return f;
        if(egg==1)
            return f;
        if(dp[egg][f]!=-1)
            return dp[egg][f];
        int mini = INT_MAX;
        for(int i=1; i<=f; i++)
        {
            int temp = 1+max(solve(egg-1, i-1), solve(egg, f-i));
            mini = min(mini, temp);
        }
        return dp[egg][f] = mini;
    }
    
    int twoEggDrop(int n) {
        memset(dp,-1,sizeof(dp));
        int ans = solve(2,n);
        return ans;
    }
};
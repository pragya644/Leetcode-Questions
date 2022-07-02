class Solution {
public:
    
    //recursion time complexity is O(n*2^2
    //dp time complexity is O()
    
    int dp[3][1001];
    
    int solve(int egg, int floor)
    {
        if(floor==1 || floor==0)
            return  floor;
        if(egg==1)
            return floor;
        if(dp[egg][floor]!=-1)
            return dp[egg][floor];
        int ans = INT_MAX;
        for(int i=1; i<=floor; i++)
        {
            int mini = 1 + max(solve(egg,floor-i),solve(egg-1,i-1));
            ans = min(ans, mini);
        }
        return dp[egg][floor] = ans;
    }
    
    int twoEggDrop(int n) {
        memset(dp,-1,sizeof(dp));
        return solve(2,n);
    }
};
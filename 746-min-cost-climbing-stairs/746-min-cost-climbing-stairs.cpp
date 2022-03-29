class Solution {
public:
//     int solve(vector<int>&cost, int i)
//     {
//         if(i<0)
//             return 0;
//         if(i==0 || i==1)
//             return cost[i];
//         return cost[i] + min(solve(cost,i-1), solve(cost, i-2));
//     }
    
    int minCostClimbingStairs(vector<int>& cost) {
        int n = cost.size();
        // return min(solve(cost,n-1), solve(cost,n-2));
        vector<int> dp(n+1);
        dp[0] = cost[0];
        dp[1] = cost[1];
        for(int i=2; i<n; i++)
        {
            dp[i] = cost[i] + min(dp[i-1], dp[i-2]);
        }
        // for(int i=2; i<=n; i++)
        // {
        //     dp[i] = min(cost[i-1]+dp[i-1], cost[i-2]+dp[i-2]);
        // }
        return min(dp[n-1],dp[n-2]);
    }
};
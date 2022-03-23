class Solution {
public:
    int memo[1001];
    
    int help(vector<int> &cost, int i)
    {
        if(i<0)
            return 0;
        if(i==1 || i==0)
            return cost[i];
        if(memo[i])
            return memo[i];
        memo[i] = cost[i] + min(help(cost,i-1), help(cost, i-2));
        return memo[i];
    }
    
    int minCostClimbingStairs(vector<int>& cost) {
        int n = cost.size();
        // int memo[n+1];
        return min(help(cost,n-1), help(cost,n-2));
        
    }
};
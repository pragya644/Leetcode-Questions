class Solution {
public:
    
    int dp[101][21][101];
    
    int solve(int h, vector<int> &houses, vector<vector<int>> &cost, int m,int n, int t,int prevCol)
    {
        if(h==m && t==0)
            return 0;
        if(h==m || t<0)
            return INT_MAX;
        if(prevCol!=-1 && t != -1 && dp[h][prevCol][t]!=-1)
            return dp[h][prevCol][t];
        int minCost = INT_MAX;
        if(houses[h]!=0)
        {
            int tempCost = 0;
            if(houses[h]==prevCol)
            {
                tempCost = solve(h+1,houses,cost,m,n,t,houses[h]);
            }
            else
                tempCost = solve(h+1,houses,cost,m,n,t-1,houses[h]);
            minCost = min(minCost,tempCost);
        }
        else
        {
            for(int i=0; i<n; i++)
            {
                int tempCost = 0;
                if(prevCol==i+1)
                {
                    tempCost = solve(h+1,houses,cost,m,n,t,i+1);
                }
                else
                    tempCost = solve(h+1,houses,cost,m,n,t-1,i+1);
                if(tempCost!=INT_MAX)
                {
                    minCost = min(minCost, cost[h][i]+tempCost);
                }
            }
        }
        
        if(prevCol!=-1 && t!=-1)
            return dp[h][prevCol][t] = minCost;
        
        return minCost;
    }
    
    
    int minCost(vector<int>& houses, vector<vector<int>>& cost, int m, int n, int target) 
    {
        //m is no of houses
        // n is no of colors
        memset(dp,-1,sizeof(dp));
        int minCost = solve(0,houses,cost,m,n,target,-1);
        return minCost == INT_MAX ? -1 : minCost;
    }
};



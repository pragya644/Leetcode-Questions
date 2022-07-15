class Solution {
public:
    
    int dp[101][101];
    
    int findCost(int rodStart, int rodEnd, vector<int>&cuts, int cutStart,int cutEnd)
    {
        if(cutStart>cutEnd)
            return 0;
        if(dp[cutStart][cutEnd]!=-1)
            return dp[cutStart][cutEnd];
        int cost = INT_MAX;
        for(int i=cutStart; i<=cutEnd; i++)
        {
          cost = min(cost, (rodEnd-rodStart) + findCost(rodStart,cuts[i],cuts,cutStart,i-1) + findCost(cuts[i],rodEnd,cuts,i+1,cutEnd));
        }
        return dp[cutStart][cutEnd]=cost;
    }
    
    int minCost(int n, vector<int>& cuts) {
        memset(dp,-1,sizeof(dp));
        sort(cuts.begin(),cuts.end());
        int noOfCuts = cuts.size();
        return findCost(0,n,cuts,0,noOfCuts-1);
    }
};
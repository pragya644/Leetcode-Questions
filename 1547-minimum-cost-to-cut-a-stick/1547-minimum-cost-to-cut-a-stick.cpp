class Solution {
public:
    
    //Time complexity is O(n^2*n) = O(n^3);
    //space complexity is O(n^2);
    
    int solve(int i, int j, vector<int> &cuts, vector<vector<int>> &dp){
        if(i>j)
            return 0;
        if(dp[i][j]!=-1)
            return dp[i][j];
        int cost = INT_MAX;
        for(int k=i; k<=j; k++){
            int mini = cuts[j+1]-cuts[i-1] + solve(i,k-1,cuts,dp) + solve(k+1,j,cuts,dp);
            cost = min(cost,mini);
        }
        return dp[i][j] = cost;
    }
    
    int minCost(int n, vector<int>& cuts) {
        sort(cuts.begin(), cuts.end());
        int size = cuts.size();
        cuts.insert(cuts.begin(),0);
        cuts.push_back(n);
        vector<vector<int>> dp(size+2,vector<int> (size+2,0));
        for(int i=size; i>0; i--)
        {
            for(int j=0; j<=size; j++)
            {
                if(i>j)
                    continue;
                int cost = INT_MAX;
                for(int k=i; k<=j; k++)
                {
                    int mini = cuts[j+1]-cuts[i-1]+dp[i][k-1]+dp[k+1][j];
                    cost = min(cost, mini);
                }
                dp[i][j] = cost;
            }
        }
        return dp[1][size];
    }
};
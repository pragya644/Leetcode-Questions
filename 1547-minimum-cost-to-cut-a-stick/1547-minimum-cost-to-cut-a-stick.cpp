class Solution {
public:
    
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
        cuts.insert(cuts.begin(),0);
        cuts.push_back(n);
        int size = cuts.size();
        vector<vector<int>> dp(size+1,vector<int> (size+1,-1));
        int i=1, j=size-2;
        return solve(i,j,cuts,dp);
    }
};
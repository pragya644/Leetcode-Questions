class Solution {
public:
    
    //Recursion : time complexity is O(2^n) where is n is no of coins 
    
    int solve(int i, vector<int> &coins, int amount,int &ans, vector<vector<int>> &dp){
        if(i>=coins.size())
            return INT_MAX-1;
        if(amount==0)
            return dp[i][amount]=0;
        if(dp[i][amount]!=-1)
            return dp[i][amount];
        if(coins[i]<=amount)
        {
            ans = min(1+solve(i,coins,amount-coins[i],ans,dp), solve(i+1,coins, amount, ans,dp));
        }
        else{
            ans = solve(i+1,coins,amount,ans,dp);
        }
        return dp[i][amount]=ans;
    }
    
    int coinChange(vector<int>& coins, int amount) {
        int ans = 0;
        int n = coins.size();
        vector<vector<int>> dp(n,vector<int>(amount+1,-1));
        int res =  solve(0,coins,amount,ans,dp);
        return res>amount?-1:res;
    }  
        
};
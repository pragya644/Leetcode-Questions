class Solution {
public:
    
    // int solve(int i, vector<int> &coins, int &amount,int &ans){
    //     if(i>=coins.size())
    //         return INT_MAX;
    //     if(amount==0)
    //         return ;
    //     if(coins[i]<=amount)
    //     {
    //         ans = ans +  min(1+solve(i,coins,amount-coins[i],ans), solve(i+1,coins, amount, ans));
    //     }
    //     else{
    //         ans += solve(i+1,coins,amount,ans);
    //     }
    // }
    
    int coinChange(vector<int>& coins, int amount) {
        // return solve(0,coins,amount);
        
        int n = coins.size();
        vector<vector<int>> dp(n+1,vector<int>(amount+1,0));
        for(int i=0; i<=amount; i++){
            dp[0][i] = INT_MAX-1;
        }
        for(int i=0; i<=n; i++){
            dp[i][0] = 0;
        }
        for(int i=1; i<=amount; i++){
            if(i%coins[0]==0){
                dp[1][i] = i/coins[0];
            }
            else{
                dp[1][i] = INT_MAX-1;
            }
        }
        for(int i=2; i<=n; i++){
            for(int j=1; j<=amount; j++){
                if(coins[i-1]<=j){
                    dp[i][j] = min(dp[i][j-coins[i-1]]+1, dp[i-1][j]);
                }else{
                    dp[i][j] = dp[i-1][j];
                }
            }
        }
        return dp[n][amount]>amount?-1:dp[n][amount];
    }
};
class Solution {
public:
    
    
    
    bool solve(int i, int sum,vector<int> &nums,vector<vector<int>> &dp){
        if(i>=nums.size() || sum<0)
            return false;
        if(dp[i][sum]!=-1)
            return dp[i][sum];
        if(sum==0)
            return dp[i][sum] = true;
        if(nums[i]<=sum)
            return dp[i][sum] = ( solve(i+1,sum-nums[i], nums,dp) || solve(i+1,sum,nums,dp));
        else
            return dp[i][sum] = solve(i+1,sum,nums,dp);
    }
    
    bool canPartition(vector<int>& nums) {
        int n = nums.size();
        int sumOfArray = 0;
        for(int i=0; i<nums.size(); i++){
            sumOfArray += nums[i];
        }
        if(sumOfArray%2!=0)
            return false;
        int desiredSum = sumOfArray/2;
        vector<vector<int>> dp(n+1, vector<int> (desiredSum+1,-1));
        return solve(0,desiredSum,nums,dp)==1?true:false;
    }
};
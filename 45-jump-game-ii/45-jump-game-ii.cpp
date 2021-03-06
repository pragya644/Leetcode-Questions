class Solution {
public:
    
    int solve(int i, vector<int> &nums, vector<int> &dp)
    {
        if(i>=nums.size()-1)
            return 0;
        if(dp[i]!=-1)
            return dp[i];
        int temp = INT_MAX-1;
        for(int j=1; j<=nums[i]; j++)
        {
            temp = min(temp, 1+solve(i+j, nums, dp));
        }
        dp[i] = temp;
        return dp[i];
    }
    
    int jump(vector<int>& nums) {
        int n = nums.size();
        vector<int> dp(n,-1);
        return solve(0,nums,dp);
    }
};
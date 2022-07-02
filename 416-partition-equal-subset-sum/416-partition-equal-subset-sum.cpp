class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int n = nums.size();
        int sumOfArray = 0;
        for(int i=0; i<nums.size(); i++){
            sumOfArray += nums[i];
        }
        if(sumOfArray%2!=0)
            return false;
        int desiredSum = sumOfArray/2;
        vector<vector<bool>> dp(n + 1, vector<bool> (desiredSum +1, false));
        for(int i=0; i<=n; i++)
            dp[i][0] = true;
        for(int i=1; i<=n; i++)
        {
            for(int j=1; j<=desiredSum; j++)
            {
                if(nums[i-1]<=j)
                {
                    dp[i][j] = dp[i-1][j-nums[i-1]] || dp[i-1][j];
                }
                else
                {
                    dp[i][j] = dp[i-1][j];
                }
            }
        }
        return dp[n][desiredSum];
    }
};
class Solution {
public:
    int deleteAndEarn(vector<int>& nums) {
        int n = 10001;
        vector<int> sum(n);
        vector<int> dp(n);
        for(int i=0; i<nums.size(); i++)
            sum[nums[i]] += nums[i];
        dp[0] = sum[0];
        dp[1] = sum[1];
        for(int i=2; i<n; i++)
            dp[i] = max(dp[i-2]+sum[i], dp[i-1]);
        return dp[n-1];
    }
};
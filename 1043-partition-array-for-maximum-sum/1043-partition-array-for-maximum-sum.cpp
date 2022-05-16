class Solution {
public:
    int maxSumAfterPartitioning(vector<int>& arr, int k) {
        int n = arr.size();
        vector<int> dp(n,0);
        dp[0] = arr[0];
        int maxi = arr[0];
        for(int i=0; i<k; i++)
        {
            maxi = max(maxi, arr[i]);
            dp[i] = maxi*(i+1);
        }
        for(int i=k; i<n; i++)
        {
            maxi = arr[i];
            for(int j=1; j<=k; j++)
            {
                maxi = max(maxi, arr[i-j+1]);
                dp[i] = max(dp[i], maxi*(j)+dp[i-j]);
            }
        }
        return dp[n-1];
    }
};
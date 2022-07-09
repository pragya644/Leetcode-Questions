class Solution {
public:
    int maxResult(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> dp(n,INT_MIN);
        dp[0] = nums[0];
        multiset<int, greater<int>> m; //decreasing order
        m.insert(dp[0]);
        for(int i=1; i<n; i++)
        {
            if(m.size()>k)
            {
                auto it = m.find(dp[i-k-1]);
                m.erase(it);
            }
            auto it = m.begin();
            dp[i] = max(dp[i], nums[i]+*it);
            m.insert(dp[i]);
        }
        return dp[n-1];
    }
};
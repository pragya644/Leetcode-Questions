class Solution {
public:
    int minimumTotal(vector<vector<int>>& t) {
        int n = t.size();
        vector<int> dp = t[n-1];
        for(int i=n-2; i>=0; i--)
        {
            for(int j=0; j<t[i].size(); j++)
                dp[j] = t[i][j] + min(dp[j], dp[j+1]);
        }
        return dp[0];
    }
};
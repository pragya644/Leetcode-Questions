class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int m = matrix.size();
        int n = matrix[0].size();
        vector<vector<int>> dp(m, vector<int> (n,0));
        for(int i=0; i<n; i++)
            dp[0][i] = matrix[0][i];
        int ans = INT_MAX;
        for(int i=1; i<m; i++)
        {
            for(int j=0; j<n; j++)
            {
                int x = INT_MAX, y = INT_MAX, z = INT_MAX;
                if(j-1>=0)
                    y = dp[i-1][j-1];
                if(j+1<n)
                    z = dp[i-1][j+1];
                x = dp[i-1][j];
                dp[i][j] = matrix[i][j] + min(x,min(y,z));
            }
        }
        for(int i=0; i<n; i++)
            ans = min(ans, dp[m-1][i]);
        return ans;
    }
};
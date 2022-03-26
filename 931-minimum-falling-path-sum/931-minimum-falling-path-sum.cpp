class Solution {
public:
    
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int n = matrix.size();
        int m = matrix[0].size();
        int dp[n][m];
        for(int j=0; j<m; j++)
            dp[0][j] = matrix[0][j];
        for(int i=1; i<n; i++)
        {
            for(int j=0; j<m; j++)
            {
                int x = INT_MAX, y = INT_MAX, z = INT_MAX;
                if(j-1>=0)
                    x = dp[i-1][j-1];
                y = dp[i-1][j];
                if(j+1<m)
                    z = dp[i-1][j+1];
                dp[i][j] = matrix[i][j] + min(x,min(y,z));
            }
        }
        int ans = INT_MAX;
        for(int j=0; j<m; j++)
            ans = min(ans, dp[n-1][j]);
        return ans;
    }
};
class Solution {
public:
    
    int solve(int i, int j, vector<vector<int>> &grid, vector<vector<int>> &dp){
        if(i<0 || i>=grid.size() || j<0 || j>=grid[0].size())
            return INT_MAX;
        if(dp[i][j]!=-1)
            return dp[i][j];
        if(i==0 && j==0)
            return dp[i][j] = grid[i][j];
        return dp[i][j] = grid[i][j] + min(solve(i-1,j,grid,dp), solve(i,j-1,grid,dp));
    }
    
    int minPathSum(vector<vector<int>>& grid) {
    
        // 1 3 1
        // 1 5 1 
        // 4 2 1
        
        // 1 4 5
        // 2 6 6
        // 6 8 7  // 7 would be the ans
        int row = grid.size();
        int col = grid[0].size();
        vector<vector<int>> dp(row,vector<int>(col,-1));
        return solve(row-1,col-1,grid,dp);
        // return grid[row-1][col-1];
    }
};
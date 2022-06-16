class Solution {
public:
    
    void solve(vector<vector<int>> &grid, int i, int j, int &temp)
    {
        if(i<0 || i>=grid.size() || j<0 || j>=grid[0].size() || grid[i][j]!=1)
            return;
        grid[i][j] = 2;
        temp += 1;
        solve(grid, i-1, j, temp);
        solve(grid, i+1, j, temp);
        solve(grid, i, j-1, temp);
        solve(grid, i, j+1, temp);
    }
    
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        int ans = 0;
        for(int i=0; i<n; i++)
        {
            for(int j=0; j<m; j++)
            {
                if(grid[i][j]==1)
                {
                    int temp = 0;
                    solve(grid, i, j, temp);
                    ans = max(ans, temp);
                }
            }
        }
        return ans;
    }
};
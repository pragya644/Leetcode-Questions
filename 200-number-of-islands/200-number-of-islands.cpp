class Solution {
public:
    
    void dfs(vector<vector<char>> &grid, int i, int j)
    {
        if(grid[i][j]=='2' || grid[i][j]=='0')
            return;
        grid[i][j] = '2';
        if(i-1>=0)
            dfs(grid, i-1, j);
        if(j-1>=0)
            dfs(grid, i, j-1);
        if(i+1<grid.size())
            dfs(grid, i+1, j);
        if(j+1<grid[0].size())
            dfs(grid, i, j+1);
    }
    
    int numIslands(vector<vector<char>>& grid) {
        int ans = 0;
        int m = grid.size();
        int n = grid[0].size();
        for(int i=0; i<m; i++)
        {
            for(int j=0; j<n; j++)
            {
                if(grid[i][j]=='1')
                {
                    dfs(grid,i,j);
                    ans++;
                }
            }
        }
        return ans;
    }
};
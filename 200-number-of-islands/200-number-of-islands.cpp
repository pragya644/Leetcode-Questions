class Solution {
public:
    void solve(vector<vector<char>>& grid, int i, int j)
    {
        if(grid[i][j]=='2' || grid[i][j]== '0')
            return;
        grid[i][j] = '2';
        if(i-1>=0)
            solve(grid,i-1,j);
        if(j-1>=0)
            solve(grid,i,j-1);
        if(i+1<grid.size())
            solve(grid,i+1,j);
        if(j+1<grid[0].size())
            solve(grid,i,j+1);
    }
    
    int numIslands(vector<vector<char>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        int ans = 0;
        for(int i=0; i<n; i++)
        {
            for(int j=0; j<m; j++)
            {
                if(grid[i][j]=='1')
                {
                    solve(grid,i,j);
                    ans++;
                }
            }
        }
        return ans;
    }
};
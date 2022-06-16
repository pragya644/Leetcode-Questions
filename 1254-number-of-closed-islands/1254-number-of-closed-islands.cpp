class Solution {
public:
    bool solve(vector<vector<int>> &grid, int i, int j)
    {
        if(i<0 || i>=grid.size() || j<0 || j>=grid[0].size())
            return false;
        if(grid[i][j]==1)
            return true;
        grid[i][j] = 1;
        bool a1 = solve(grid, i+1, j);
        bool a2 = solve(grid, i-1, j);
        bool a3 = solve(grid, i, j+1);
        bool a4 = solve(grid, i, j-1);
        return a1 && a2 && a3 && a4;
    }
    
    int closedIsland(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        int res = 0;
        for(int i=0; i<n; i++)
        {
            for(int j=0; j<m; j++)
            {
                if(grid[i][j]==0)
                {
                    if(solve(grid,i,j))
                        res++;
                }
            }
        }
        return res;
    }
};
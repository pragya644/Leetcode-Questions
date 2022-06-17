class Solution {
public:
    
    bool solve(vector<vector<int>> &grid, int i,int j, int &temp)
    {
        if(i<0 || i>=grid.size() || j<0 || j>=grid[0].size())
            return false;
        if(grid[i][j]==0)
            return true;
        grid[i][j] = 0;
        temp += 1;
        bool b1 = solve(grid,i+1,j,temp);
        bool b2 = solve(grid,i-1,j,temp);
        bool b3 = solve(grid,i,j+1,temp);
        bool b4 = solve(grid,i,j-1,temp);
        return b1 && b2 && b3 && b4;
    }
    
    int numEnclaves(vector<vector<int>>& grid) {
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
                    if(solve(grid,i,j,temp)==true)
                    {
                        ans += temp;
                    }
                }
            }
        }
        return ans;
    }
};
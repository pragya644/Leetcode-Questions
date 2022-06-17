class Solution {
public:
    bool solve(vector<vector<int>> &grid1, vector<vector<int>> &grid2,int i, int j)
    {
        if(i<0 || i>=grid1.size() || j<0 || j>=grid1[0].size() || grid2[i][j]==0)
            return true;
        if(grid1[i][j]==0 && grid2[i][j]==0)
            return true;
        if(grid1[i][j]==0 && grid2[i][j]==1)
            return false;
        grid1[i][j] = 0;
        grid2[i][j] = 0;
        int b1 = solve(grid1,grid2, i-1,j);
        int b2 = solve(grid1,grid2, i+1,j);
        int b3 = solve(grid1,grid2, i,j-1);
        int b4 = solve(grid1,grid2, i,j+1);
        
        return b1 && b2 && b3 && b4;
    }
    
    int countSubIslands(vector<vector<int>>& grid1, vector<vector<int>>& grid2) {
        int n = grid1.size();
        int m = grid1[0].size();
        int ans = 0;
        for(int i=0; i<n; i++)
        {
            for(int j=0; j<m; j++)
            {
                if(grid1[i][j]==1 && grid2[i][j]==1)
                {
                    if(solve(grid1, grid2,i,j))
                        ans++;
                }
            }
        }
        return ans;
    }
};
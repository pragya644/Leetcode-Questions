class Solution {
public:
    void dfs(vector<vector<char>> &mat, int i,int j)
    {
        if(mat[i][j]=='2' || mat[i][j]=='0')
            return;
        if(mat[i][j]=='1')
        {
            mat[i][j] = '2';
            if(i-1>=0)
                dfs(mat,i-1,j);
            if(j-1>=0)
                dfs(mat,i,j-1);
            if(i+1<mat.size())
                dfs(mat,i+1,j);
            if(j+1<mat[0].size())
                dfs(mat,i,j+1);
        }
    }
    
    int numIslands(vector<vector<char>>& grid) {
        int res = 0;
        for(int i=0; i<grid.size(); i++)
        {
            for(int j=0; j<grid[0].size(); j++)
            {
                if(grid[i][j]=='1')
                {
                    dfs(grid,i,j);
                    res++;
                }
            }
        }
        return res;
    }
};
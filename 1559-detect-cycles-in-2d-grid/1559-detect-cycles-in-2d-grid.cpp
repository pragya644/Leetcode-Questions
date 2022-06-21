class Solution {
public:
    
    vector<pair<int,int>> dir = {{-1,0},{1,0},{0,1},{0,-1}};
    
    bool dfs(vector<vector<char>> &grid, vector<vector<bool>> &vis,int i, int j,int p_i, int p_j)
    {
        vis[i][j] = true;
        for(int k=0; k<4; k++)
        {
            int r = i + dir[k].first;
            int c = j+ dir[k].second;
            if(r>=0 && c>=0 && r<grid.size() && c<grid[0].size() && grid[r][c]==grid[i][j] && !(r==p_i && c==p_j)) 
            {
                if(vis[r][c] || dfs(grid,vis,r,c,i,j))
                    return true;
            }
        }
        return false;
    }
    
    
    bool containsCycle(vector<vector<char>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<bool>> vis(n, vector<bool> (m,false));
        for(int i=0; i<n; i++)
        {
            for(int j=0; j<m; j++)
            {               
                if(vis[i][j]==false && dfs(grid,vis,i,j,-1,-1))
                    return true;
            }
        }
        return false;
    }
};
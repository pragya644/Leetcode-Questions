class Solution {
public:
    
    void dfs(vector<vector<int>>&h,int i,int j,vector<vector<bool>>&v,int prev)
    {
        if(i<0 || i>=h.size()|| j<0 || j>=h[0].size() || v[i][j] || h[i][j]<prev)
            return;
        v[i][j] = true;
        dfs(h,i-1,j,v,h[i][j]);
        dfs(h,i,j-1,v,h[i][j]);
        dfs(h,i,j+1,v,h[i][j]);
        dfs(h,i+1,j,v,h[i][j]);
    }
    
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& h) {
        int n = h.size();
        int m = h[0].size();
        vector<vector<bool>> pac(n+1,vector<bool>(m+1,false));
        vector<vector<bool>> atl(n+1,vector<bool>(m+1,false));
        for(int i=0; i<m; i++){
            dfs(h,0,i,pac,h[0][i]);
            dfs(h,n-1,i,atl, h[n-1][i]);
        }
        for(int i=0; i<n; i++)
        {
            dfs(h,i,0,pac,h[i][0]);
            dfs(h,i,m-1,atl,h[i][m-1]);
        }
        
        vector<vector<int>> ans;
        
        for(int i=0; i<n; i++)
        {
            for(int j=0; j<m; j++)
            {
                if(pac[i][j] && atl[i][j])
                    ans.push_back({i,j});
            }
        }
        return ans;
    }
};
class Solution {
public:
    
    void dfs(vector<vector<int>> &isConnected, vector<bool> &vis, int u)
    {
        vis[u] = true;
        for(int v=0; v<vis.size(); v++)
            if(vis[v]==false && v!=u && isConnected[u][v]==1)
                dfs(isConnected, vis, v);
    }
    
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n = isConnected.size();
        if(n==0)
            return 0;
        vector<bool> vis(n, false);
        int count = 0;
        for(int i=0; i<n; i++)
        {
            if(vis[i]==false)
            {
                dfs(isConnected, vis, i);
                count++;
            }
        }
        return count;
    }
};
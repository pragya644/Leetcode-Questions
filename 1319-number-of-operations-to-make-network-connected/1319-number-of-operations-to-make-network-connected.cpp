class Solution {
public:
    
    void dfs(vector<vector<int>> &adj, vector<bool> &vis, int i)
    {
        vis[i] = true;
        for(auto x: adj[i])
        {
            if(vis[x]==false)
                dfs(adj,vis,x);
        }
    }
    
    int makeConnected(int n, vector<vector<int>>& c) {
        if(c.size()<n-1)
            return -1; //means total cabels is less than no of nodes in that case it is impossible to connect all the nodes so directly return -1;
        vector<bool> vis(n,false);
        vector<vector<int>> adj(n);
        for(int i=0; i<c.size(); i++)
        {
            adj[c[i][0]].push_back(c[i][1]);
            adj[c[i][1]].push_back(c[i][0]);
        }
        int ans = 0;
        for(int i=0; i<n; i++)
        {
            if(vis[i]==false) {
                ans++;
                dfs(adj,vis,i);
            }
        }
        return ans-1;;
    }
};
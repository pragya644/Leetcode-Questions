class Solution {
public:
    
    void dfs(int i, int &node, vector<vector<int>> &adj,vector<bool> &vis)
    {
        node++;
        vis[i] = true;
        for(auto x: adj[i])
        {
            if(vis[x]==false)
                dfs(x,node,adj,vis);
        }
    }
    
    long long countPairs(int n, vector<vector<int>>& edges) {
        vector<vector<int>> adj(n);
        for(int i=0; i<edges.size(); i++){
            adj[edges[i][0]].push_back(edges[i][1]);
            adj[edges[i][1]].push_back(edges[i][0]);
        }
        long long int total = 0, ans = 0;
        vector<bool> vis(n,false);
        for(int i=0; i<n; i++){
            if(vis[i]==false)
            {
                int n = 0;
                dfs(i,n,adj,vis);
                ans += total*n;
                total += n;
            }
        }
        return ans;
    }
};
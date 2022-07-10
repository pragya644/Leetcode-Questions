class Solution {
public:
    
    bool dfs(int i, vector<int> adj[],vector<bool> &vis, int p)
    {
        vis[i] = true;
        for(auto x: adj[i])
        {
            if(vis[x]==false)
            {
                if(dfs(x,adj,vis,i))
                    return true;
            }
            else if(x!=p)
            {
                return true;
            }
        }
        return false;
    }
    
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        int n = edges.size();
        vector<int> adj[n+1];
        int a,b;
        for(auto x: edges)
        {
            vector<bool> vis(n+1,false);
            int node = x[0];
            int child = x[1];
            adj[node].push_back(child);
            adj[child].push_back(node);
            if(dfs(node,adj,vis,-1))
            {
                a = node;
                b = child;
                adj[node].pop_back();
                adj[child].pop_back();
            }
        }
        return {a,b};
    }
};
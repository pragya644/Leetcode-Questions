class Solution {
public:
    bool iscyclic(vector<vector<int>> &adj, vector<int> &vis, int i)
    {
        if(vis[i]==2)
            return true;
        vis[i] = 2;
        for(int j=0; j<adj[i].size(); ++j)
        {
            if(vis[adj[i][j]]!=1)
            {
                if(iscyclic(adj,vis,adj[i][j]))
                    return true;
            }
        }
        vis[i] = 1;
        return false;
    }
    
    bool canFinish(int n, vector<vector<int>>& pre) {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        cout.tie(NULL);
        
        
        vector<vector<int>> adj(n);
        for(int i=0; i<pre.size(); i++)
        {
            adj[pre[i][0]].push_back(pre[i][1]);
        }
        vector<int> vis(n,0);
        for(int i=0; i<n; i++)
        {
            if(vis[i]==0)
            {
                if(iscyclic(adj,vis,i))
                    return false;
            }
        }
        return true;
    }
};




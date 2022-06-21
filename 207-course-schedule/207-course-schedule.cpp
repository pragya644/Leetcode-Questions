class Solution {
public:
    
    bool dfs(vector<vector<int>> &adj, vector<int> &vis, vector<bool> &temp, int i) {
        if(temp[i])
            return false;
        if(vis[i]==1)
            return true;
        vis[i] = 1;
        temp[i] = true;
        for(auto x: adj[i]) {
            if(dfs(adj,vis,temp,x)==false)
                return false;
        }
        temp[i] = false;
        return true;
    }
    
    bool canFinish(int n, vector<vector<int>>& pre) {
        vector<vector<int>> adj(n);
        for(int i=0; i<pre.size(); i++) {
            adj[pre[i][0]].push_back(pre[i][1]);
        }
        vector<bool> temp(n,false);
        vector<int> vis(n,0);
        for(int i=0; i<n; i++)
        {
            if(vis[i]==0)
            {
                if(dfs(adj,vis,temp,i)==false)
                    return false;
            }
        }
        return true;
    }
    
    
    
};
class Solution {
public:
    bool solve(int i, int d, vector<vector<int>> &v, vector<int> &vis)
    {
        if(i==d)
            return true;
        if(vis[i]==false)
            return false;
        vis[i] = false;
        for(auto x: v[i])
            if(solve(x,d,v,vis))
                return true;
        return false;
    }
    
bool validPath(int n, vector<vector<int>>& edges, int source, int destination) {
        vector<vector<int>> v(n);
        for(int i=0; i<edges.size(); i++)
        {
            v[edges[i][0]].push_back(edges[i][1]);
            v[edges[i][1]].push_back(edges[i][0]);
        }
        vector<int> vis(n, true);
        return solve(source,destination,v,vis);
    }
};
class Solution {
public:
    bool validPath(int n, vector<vector<int>>& edges, int source, int destination) {
        vector<vector<int>> v(n);
        for(int i=0; i<edges.size(); i++)
        {
            v[edges[i][0]].push_back(edges[i][1]);
            v[edges[i][1]].push_back(edges[i][0]);
        }
        vector<int> vis(n, true);
        queue<int> q;
        q.push(source);
        while(q.empty()==false)
        {
            int curr = q.front();
            q.pop();
            if(curr == destination)
                return true;
            vis[curr] = false;
            for(auto x: v[curr])
            {
                if(vis[x])
                {
                    q.push(x);
                }
            }
        }
        return false;
    }
};
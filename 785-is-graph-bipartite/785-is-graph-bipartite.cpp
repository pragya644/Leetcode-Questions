class Solution {
public:
    bool isBipartite(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<int> col(n,0);
        queue<int> q;
        for(int i=0; i<n; i++)
        {
            if(col[i]!=0)
                continue;
            col[i] = 1;
            q.push(i);
            while(q.empty()==false)
            {
                int curr = q.front();
                q.pop();
                for(auto v: graph[curr])
                {
                    if(col[v]==0)
                    {
                        col[v] = -col[curr];
                        q.push(v);
                    }
                    else
                        if(col[v]==col[curr])
                            return false;
                }
            }
        }
        return true;
    }
};
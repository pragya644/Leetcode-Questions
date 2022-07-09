class Solution {
public:
    //bfs
    //time complexity is O(V+E) bcoz we are every visting node only once;
    bool solve(int i, vector<vector<int>> &graph, vector<int> &col)
    {
        queue<int> q;
        q.push(i);
        while(q.empty()==false)
        {
            auto curr = q.front();
            q.pop();
            for(auto x: graph[curr])
            {
                if(col[x]==col[curr])
                    return false;
                if(col[x]==0)
                {
                    col[x] = -col[curr];
                    q.push(x);
                }
            }
        }
        return true;
    }
    
    bool isBipartite(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<int> col(n,0);
        for(int i=0; i<n; i++)
        {
            if(col[i]==0)
            {
                col[i] = 1;
                if(solve(i,graph,col)==false)
                     return false;
            }
        }
        return true;
    }
};
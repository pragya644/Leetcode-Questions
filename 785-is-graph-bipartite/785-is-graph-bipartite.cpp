class Solution {
public:
    
    //time complexity is O(V+E) bcoz we are every visting node only once;
    bool solve(int i, vector<vector<int>> &graph, vector<int> &col)
    {
        for(auto x: graph[i])
        {
            if(col[x]==col[i])
                return false;
            else if(col[x]==0)
            {
                col[x] = -col[i];
                if(solve(x,graph,col)==false)
                    return false;
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
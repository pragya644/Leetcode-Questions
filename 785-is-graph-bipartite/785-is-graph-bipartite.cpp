class Solution {
public:
    
    bool solve(vector<vector<int>> &graph, vector<int> &color, int curr)
    {
        for(auto v: graph[curr])
        {
            if(color[v]==color[curr])
                return false;
            else if(color[v]==0){
            color[v] = -color[curr];
            if(solve(graph, color, v)==false)
                return false;
            }
        }
        return true;
    }
    
    bool isBipartite(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<int> color(n,0);
        for(int i=0; i<n; i++)
        {
            if(color[i]==0)
            {
                color[i] = 1;
                if(solve(graph, color, i)==false)
                    return false;
            }
        }
        return true;
    }
};
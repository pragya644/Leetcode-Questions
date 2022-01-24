class Solution {
public:
    void bfs(vector<vector<int>>& graph,vector<vector<int>> &ans )
    {
        queue<vector<int>> q;
        q.push({0});
        while(q.empty()==false)
        {
            vector<int> path = q.front();
            q.pop();
            int u= path[path.size()-1]; //last node
            for(auto v : graph[u])
            {
                path.push_back(v);
                if(v==graph.size()-1)
                    ans.push_back(path);
                else
                    q.push(path);
                path.pop_back();
            }
        }
    }
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        vector<vector<int>> ans;
        bfs(graph, ans);
        return ans;
    }
};
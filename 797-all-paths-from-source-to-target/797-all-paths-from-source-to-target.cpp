class Solution {
public:
    
    void solve(vector<vector<int>> &graph, int i, vector<int> &temp, vector<vector<int>> &ans) {
        if(i==graph.size()-1)
        {
            temp.push_back(i);
            ans.push_back(temp);
            temp.pop_back();
            return;
        }
        temp.push_back(i);
        for(auto x: graph[i]){
            solve(graph,x,temp,ans);
        }
        temp.pop_back();
    }
    
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        vector<vector<int>> ans;
        int n = graph.size();
        vector<int> temp;
        solve(graph,0,temp,ans);
        return ans;
    }
};
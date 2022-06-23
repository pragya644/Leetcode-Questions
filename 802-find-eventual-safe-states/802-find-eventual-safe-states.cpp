class Solution {
public:
    
    bool is_safe_node(int node, vector<vector<int>> &graph, vector<bool> &safe, unordered_set<int> &curr_vis,vector<bool> &vis)
    {
        vis[node] = true;
        curr_vis.insert(node);
        for(auto x: graph[node])
        {
            if(vis[x]==false){
                if(is_safe_node(x,graph,safe,curr_vis,vis)==false){
                    return safe[node] = false;
                }
            }
            else if(curr_vis.find(x)!=curr_vis.end())
                return safe[node] = false;
        }
        curr_vis.erase(node);
        return safe[node];
    }
    
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int no_of_nodes = graph.size();
        vector<bool> safe(no_of_nodes,true);
        vector<bool> vis(no_of_nodes, false);
        vector<int> ans;
        unordered_set<int> curr_vis;
        bool flag = true;
        for(int i=0; i<no_of_nodes; i++) {
            if(vis[i]==false) {
                is_safe_node(i,graph,safe,curr_vis,vis);
            }
        }
        for(int i=0; i<no_of_nodes; i++){
            if(safe[i]==true)
                ans.push_back(i);
        }
        return ans;
    }
};
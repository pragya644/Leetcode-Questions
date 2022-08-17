class Solution {
public:
    
    // dfs cycle checking
    //time complexity is O(V+E)
    
    bool isCycle(int i,vector<bool> &vis,vector<bool> &currVis, vector<vector<int>> &adj){
        if(vis[i]==true){ //to prevent tle
            return false;
        }
        vis[i] = true;
        currVis[i] = true;
        for(auto x: adj[i]){
            if(currVis[x]==false && isCycle(x,vis,currVis,adj)){
                return true;
            }else if(currVis[x]){
                return true;
            }
        }
        currVis[i] = false;
        return false;
    }
    
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> adj(numCourses);
        for(auto x: prerequisites){
            adj[x[0]].push_back(x[1]);
        }
        vector<bool> vis(numCourses,false);
        vector<bool> currVis(numCourses,false);
        for(int i=0; i<numCourses; i++){
            if(vis[i]==false){
                if(isCycle(i,vis,currVis,adj)){
                    return false;
                }
            }
        }
        return true;
    }
};
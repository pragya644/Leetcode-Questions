class Solution {
public:
    
    bool isCycle(int i, vector<vector<int>> &adj, vector<bool> &vis, vector<bool> &temp)
    {
        if(vis[i]==true)
            return false;
        vis[i] = true;
        temp[i]= true;
        for(auto x: adj[i])
        {
            if(temp[x]==false){
                if(isCycle(x,adj,vis,temp))
                    return true;
            }else{
                return true;
            }
        }
        temp[i] = false;
        return false;
    }
    
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> adj(numCourses);
        for(int i=0; i<prerequisites.size(); i++)
        {
            adj[prerequisites[i][0]].push_back(prerequisites[i][1]);
        }
        vector<bool> vis(numCourses,false);
        vector<bool> tempVis(numCourses,false);
        for(int i=0; i<numCourses; i++)
        {
            if(vis[i]==false){
            if(isCycle(i,adj,vis,tempVis))
                return false;
            }
        }
        return true;
    }
};
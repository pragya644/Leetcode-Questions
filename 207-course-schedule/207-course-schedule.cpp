class Solution {
public:
    
    // troplogical sort or bfs cycle checking
    //time complexity is O(V+E)
    
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> adj(numCourses);
        for(auto x: prerequisites){
            adj[x[0]].push_back(x[1]);
        }
        vector<int> inDegree(numCourses, 0);
        for(int i=0; i<numCourses; i++){
            for(auto x: adj[i]){
                inDegree[x]++;
            }
        } 
        queue<int> q;
        for(int i=0; i<numCourses; i++){
            if(inDegree[i]==0){
                q.push(i);
            }
        }
        int count = 0;
        vector<bool> vis(numCourses,false);
        while(q.empty()==false){
            auto curr = q.front();
            q.pop();
            vis[curr] = true;
            count++;
            for(auto x: adj[curr]){
                if(vis[x]==true)
                    continue;
                inDegree[x]--;
                if(inDegree[x]==0){
                    q.push(x);
                }
            }
        }
        if(count == numCourses)
            return true;
        return false;
    }
};
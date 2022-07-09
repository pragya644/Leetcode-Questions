class Solution {
public:
    //tropolgoical sorting
    // time Complexity would be O(V+E)
    //space Complexity is O(V+E)
    
    bool canFinish(int n, vector<vector<int>>& pre) {
        vector<vector<int>> adj(n);
        int mustCourse = pre.size();
        for(int i=0; i<mustCourse; i++)
        {
            adj[pre[i][0]].push_back(pre[i][1]);
        }
        vector<int> inDegree(n,0);
        for(int i=0; i<n; i++)
        {
            for(auto node: adj[i]){
                inDegree[node]++;
            }
        }
        queue<int> nodeWith0Degree;
        for(int i=0; i<n; i++){
            if(inDegree[i]==0)
                nodeWith0Degree.push(i);
        }
        int visNode = 0;
        while(nodeWith0Degree.empty()==false)
        {
            int currNode = nodeWith0Degree.front();
            nodeWith0Degree.pop();
            for(auto node: adj[currNode])
            {
                inDegree[node]--;
                if(inDegree[node]==0)
                {
                    nodeWith0Degree.push(node);
                }
            }
            visNode++;
        }
        if(visNode!=n)
            return false;
        return true;
    }
};
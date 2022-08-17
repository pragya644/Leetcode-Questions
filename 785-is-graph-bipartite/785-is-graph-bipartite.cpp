class Solution {
public:
    bool isBipartite(vector<vector<int>>& graph) {
        int numOfNode = graph.size();
        vector<int> color(numOfNode, 0);
        queue<int> q;
        for(int i=0; i<numOfNode; i++){
            if(color[i]!=0)
                continue;
            color[i] = 1;
            q.push(i);
            while(q.empty()==false){
                auto curr = q.front();
                q.pop();
                for(auto x: graph[curr]){
                    if(color[x]==0){
                        color[x] = -color[curr];
                        q.push(x);
                    }
                    if(color[x]==color[curr])
                        return false;
                }
            }
        }
        return true;
    }
};
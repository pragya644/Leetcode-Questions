class Solution {
public:
    
    bool sameColor(int i, vector<int> &color,int currColor, vector<vector<int>>& graph){
        if(color[i]==0){
            color[i] = currColor;
        }
        for(auto x: graph[i]){
            if(color[x]==0){
                if(sameColor(x,color,-color[i], graph))
                    return true;
            }else if(color[x]==color[i]){
                return true;
            }
        }
        return false;
    }
    
    bool isBipartite(vector<vector<int>>& graph) {
        int numOfNode = graph.size();
        vector<int> color(numOfNode, 0);
        for(int i=0; i<numOfNode; i++){
            if(color[i]==0){
                int currColor = 1;
                if(sameColor(i,color,currColor,graph))
                    return false;
            }
        }
        return true;
    }
};
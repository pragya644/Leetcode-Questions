class Solution {
public:
    
    void dfs(string u, string v,double &dis,double &currDis,bool &flag, map<string,vector<pair<string,double>>> graph,unordered_set<string> &vis){
        if(vis.find(u)!=vis.end())
            return;
        vis.insert(u);
        if(u==v){
            dis = currDis;
            flag = true;
            return;
        }
        for(auto x: graph[u]){
            currDis *= x.second;
            dfs(x.first,v,dis,currDis,flag,graph,vis);
            if(flag==true){
                return;
            }
            currDis = currDis/x.second;
        }
    }
    
    vector<double> calcEquation(vector<vector<string>>& equations, vector<double>& values, vector<vector<string>>& queries) {
        
        map<string,vector<pair<string,double>>> graph;  // start end dis
        int noOfEqn = equations.size();
        for(int i=0; i<noOfEqn; i++){
            string start = equations[i][0];
            string end = equations[i][1];
            double disFromStartToEnd = values[i];
            double disFromEndToStart = 1/values[i];
            graph[start].push_back({end,disFromStartToEnd});
            graph[end].push_back({start,disFromEndToStart});
        }
        
        vector<double> ans;
        for(auto x: queries){
            string u = x[0];
            string v = x[1];
            if(graph.find(u)==graph.end() || graph.find(v)==graph.end()){
                ans.push_back(-1);
                continue;
            }
            if(u==v){
                ans.push_back(1);
                continue;
            }
            double dis = 1;
            double currDis = 1;
            bool flag = false;
            unordered_set<string> vis;
            dfs(u,v,dis,currDis,flag,graph,vis);
            if(flag==true)
                ans.push_back(dis);
            else
                ans.push_back(-1);
        }
        return ans;
    }
};
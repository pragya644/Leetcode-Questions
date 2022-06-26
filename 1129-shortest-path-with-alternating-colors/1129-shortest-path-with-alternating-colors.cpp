class Solution {
public:
    vector<int> shortestAlternatingPaths(int n, vector<vector<int>>& redEdges, vector<vector<int>>& blueEdges) {
        vector<vector<int>> red(n);
        vector<vector<int>> blue(n);
        for(int i=0; i<redEdges.size(); i++){
            red[redEdges[i][0]].push_back(redEdges[i][1]);
        }
        for(int i=0; i<blueEdges.size(); i++){
            blue[blueEdges[i][0]].push_back(blueEdges[i][1]);
        }
        vector<pair<int,int>> dis(n,{INT_MAX,INT_MAX});
        dis[0] = {0,0};
        queue<pair<int,int>> q;
        q.push({0,1}); //1 for red staring
        q.push({0,-1}); // -1 for blue starting
        int curr_dis = 0;
        while(q.empty()==false)
        {
            int n = q.size();
            for(int i=0; i<n; i++)
            {
                auto x = q.front();
                q.pop();
                int node = x.first;
                int col = x.second;
                if(col==1)
                {
                    for(auto x: blue[node])
                    {
                        if(dis[x].second>curr_dis+1)
                        {
                            q.push({x,-1});
                            dis[x].second = curr_dis+1;
                        }
                    }
                }
                else
                {
                    for(auto x: red[node])
                    {
                        if(dis[x].first>curr_dis+1)
                        {
                            q.push({x,1});
                            dis[x].first = curr_dis+1;
                        }
                    }
                }
            }
            curr_dis++;
        }
        vector<int> ans(n);
        for(int i=0; i<n; i++)
        {
            int mini = min(dis[i].second,dis[i].first);
            ans[i] = (mini==INT_MAX)?-1:mini;
        }
        return ans;
    }
};
class Solution {
public:
    int minCostConnectPoints(vector<vector<int>>& points) {
        int n = points.size();
        vector<bool> vis(n,false);
        vector<int> dis(n,INT_MAX);
        dis[0] = 0;
        int edgeused = 0;
        int cost = 0;
        while(edgeused < n)
        {
            int curr_dis = INT_MAX;
            int curr_edge = -1;
            for(int i=0; i<n; i++)
            {
                if(!vis[i] && curr_dis > dis[i])
                {
                    curr_dis = dis[i];
                    curr_edge = i;
                }
            }
            cost += curr_dis;
            vis[curr_edge] = true;
            for(int i=0; i<n; i++)
            {
                int w = abs(points[i][0]-points[curr_edge][0]) + abs(points[i][1]-points[curr_edge][1]);
                if(w<dis[i] && vis[i]==false)
                    dis[i] = w;
            }
            edgeused++;
        }
        return cost;
    }
};
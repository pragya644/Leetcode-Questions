class Solution {
public:
    int minCostConnectPoints(vector<vector<int>>& points) {
        int n = points.size();
        priority_queue<pair<int,int>, vector<pair<int,int>> , greater<pair<int,int>>> pq;
        pq.push({0,0}); 
        int edgeused = 0;
        vector<bool> vis(n,false);
        int cost = 0;
        while(edgeused<n)
        {
            auto curr = pq.top();
            pq.pop();
            int weight = curr.first;
            int curr_node = curr.second;
            if(vis[curr_node]==true)
                continue;
            vis[curr_node] = true;
            cost += weight;
            for(int i=0; i<n; i++)
            {
                if(vis[i]==false)
                {
                    int w = abs(points[i][0]-points[curr_node][0]) + abs(points[i][1]-points[curr_node][1]);
                    pq.push({w,i});
                }
            }
            edgeused++;
        }
        return cost;
    }
};
class Solution {
public:
    
    //dijkstra algorithm
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        int ans = INT_MIN;
        vector<pair<int,int>> graph[n+1];
        for(int i=0; i<times.size(); i++)
        {
            graph[times[i][0]].push_back({times[i][1], times[i][2]});
        }
        priority_queue<pair<int,int> , vector<pair<int,int>> , greater<pair<int,int>>> pq;
        vector<int> dis(n+1, INT_MAX);
        dis[k] = 0;
        pq.push({0,k});
        while(pq.empty()==false)
        {
            auto curr = pq.top();
            pq.pop();
            int prv = curr.second;
            vector<pair<int,int>>:: iterator it;
            for(auto it: graph[prv])
            {
                int next = it.first;
                int next_dis = it.second;
                int d = dis[prv]+next_dis;
                if(dis[next] > d)
                {
                    dis[next] = d;
                    pq.push({dis[next], next});
                }
            }
        }
        for(int i=1; i<=n; i++)
        {
            ans = max(ans, dis[i]);
        }
        if(ans==INT_MAX)
            return -1;
        return ans;
    }
};
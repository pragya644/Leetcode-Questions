class Solution {
public:
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        int n = rooms.size();
        vector<bool> vis(n, false);
        queue<int> q;
        for(int i=0; i<rooms[0].size(); i++)
            q.push(rooms[0][i]);
        vis[0] =  true;
        while(q.empty()==false)
        {
            int m = q.size();
            for(int i=0; i<m; i++)
            {
                int x = q.front();
                q.pop();
                if(vis[x]==false)
                {
                    for(auto y: rooms[x])
                        q.push(y);
                }
                vis[x] = true;
            }
        }
        for(int i=0; i<n; i++)
        {
            if(vis[i]==false)
                return false;
        }
        return true;
    }
};
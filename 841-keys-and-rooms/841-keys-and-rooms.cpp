class Solution {
public:
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        int n = rooms.size();
        vector<bool> vis(n,false);
        vis[0] = true;
        queue<int> q;
        q.push(0);
        while(q.empty()==false)
        {
            auto curr = q.front();
            q.pop();
            for(auto x: rooms[curr])
            {
                if(vis[x]==false)
                {
                    q.push(x);
                    vis[x] = true; 
                }
            }
        }
        for(auto x: vis)
        {
            if(x==false)
                return false;
        }
        return true;
    }
};
class Solution {
public:
    int minimumJumps(vector<int>& forbidden, int a, int b, int x) {
        unordered_set<int> s_f;
        for(auto x: forbidden)
            s_f.insert(x);
        queue<pair<int,int>> q;
        vector<pair<int,int>> vis(6000,{false,false});
        q.push({0,1});
        vis[0] = {true,true};
        int dis = 0;
        while(q.empty()==false)
        {
            dis++;
            int n = q.size();
            for(int i=0; i<n; i++)
            {
                auto curr = q.front();
                q.pop();
                int val = curr.first;
                int dir = curr.second;
                if(val==x)
                    return dis-1;
                if(s_f.find(val)!=s_f.end())
                    continue;
                if(val+a<6000 && vis[val+a].first==false)
                {
                    q.push({val+a,1});
                    vis[val+a].first = true;
                }
                if(dir!=-1 && val-b>0 && vis[val-b].second==false)
                {
                    q.push({val-b,-1});
                    vis[val-b].second = true;
                }
            }
        }
        return -1;                  
    }
};
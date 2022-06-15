class Solution {
public:
    vector<vector<int>> floodFill(vector<vector<int>>& i, int sr, int sc, int color) {
        queue<pair<int,int>> q;
        q.push({sr,sc});
        vector<vector<int>>vis(i.size(),vector<int>(i[0].size(),0));
        vector<pair<int,int>> d = {{-1,0}, {1,0}, {0,-1}, {0,1}};
        int m = i.size();
        int n = i[0].size();
        while(q.empty()==false)
        {
            auto curr = q.front();
            q.pop();
            int x = curr.first;
            int y = curr.second;
            int initial_color = i[x][y];
            i[x][y] = color;
            vis[x][y] = 1;
            for(int k=0; k<4; k++)
            {
                int r = x + d[k].first;
                int c = y + d[k].second;
                if(r>=0 && r<m && c>=0 && c<n && i[r][c] == initial_color && vis[r][c]==0)
                    q.push({r,c});
            }
        }
        return i;
    }
};
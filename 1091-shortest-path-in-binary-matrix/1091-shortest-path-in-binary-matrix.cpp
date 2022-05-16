class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        if(grid[0][0]==1)
            return -1;
        int n = grid.size();
        int m = grid[0].size();
        vector<pair<int,int>> dir{{0,-1},{-1,0},{0,1},{1,0},{-1,-1},{1,1},{-1,1},{1,-1}};
        queue<pair<int,int>> q;
        q.push({0,0});
        grid[0][0] = 1;
        while(q.empty()==false)
        {
            auto curr = q.front();
            q.pop();
            int x = curr.first;
            int y = curr.second;
            if(x==n-1 && y==m-1)
                return grid[x][y];
            for(auto d: dir)
            {
                int r = x + d.first;
                int c = y + d.second;
                if(r>=0 && c>=0 && r<n && c<m && grid[r][c]==0)
                {
                    q.push({r,c});
                    grid[r][c] = grid[x][y]+1;
                }
            }
        }
        return -1;
    }
};
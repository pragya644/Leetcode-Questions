class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        if(grid[0][0]==1)
            return -1;
        int m = grid.size();
        int n = grid[0].size();
        queue<pair<int,int>> q;
        q.push({0,0});
        vector<vector<int>> dir = {{0,1},{1,0},{-1,0},{0,-1},{1,1},{1,-1},{-1,1},{-1,-1}};
        grid[0][0] = 1;
        while(q.empty()==false)
        {
            auto curr = q.front();
            int x = curr.first;
            int y = curr.second;
            if(x==m-1 && y==n-1)
                return grid[x][y];
            for(auto d : dir)
            {
                int r = x + d[0];
                int c = y + d[1];
                if(r>=0 && c>=0 && r<m && c<n && grid[r][c]==0)
                {
                    q.push({r,c});
                    grid[r][c] = grid[x][y] + 1;
                }
            }
            q.pop();
        }
        return -1;
    }
};
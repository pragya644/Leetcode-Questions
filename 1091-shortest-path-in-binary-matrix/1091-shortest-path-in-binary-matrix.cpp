class Solution {
    
    private:
    struct point
    {
        int row;
        int col;
        int dis;
    };
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        if(grid[0][0]==1)
            return -1;
        int m = grid.size();
        int n = grid[0].size();
        queue<point> q;
        q.push({0,0,1});
        vector<vector<int>> dir = {{0,1},{1,0},{-1,0},{0,-1},{1,1},{1,-1},{-1,1},{-1,-1}};
        grid[0][0] = 1;
        while(q.empty()==false)
        {
            point curr = q.front();
            int x = curr.row;
            int y = curr.col;
            if(x==m-1 && y==n-1)
                return curr.dis;
            for(auto d : dir)
            {
                int r = x + d[0];
                int c = y + d[1];
                if(r>=0 && c>=0 && r<m && c<n && grid[r][c]==0)
                {
                    q.push({r,c,curr.dis+1});
                    grid[r][c] = 1;
                }
            }
            q.pop();
        }
        return -1;
    }
};
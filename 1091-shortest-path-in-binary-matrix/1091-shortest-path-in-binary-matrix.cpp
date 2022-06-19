class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        if(grid[0][0]==1)
            return -1;
        vector<pair<int,int>> dir = {{-1,0}, {1,0}, {0,1},{0,-1},{-1,-1}, {-1,1},{1,-1}, {1,1}};
        queue<pair<int,int>> q;
        q.push({0,0});
        grid[0][0] = 1;
        while(q.empty()==false) {
                auto curr = q.front();
                q.pop();
                int x = curr.first;
                int y  = curr.second;
                if(x==n-1 && y==m-1)
                    return grid[x][y];
                for(int i=0; i<8; i++)
                {
                    int row = x+dir[i].first;
                    int col = y+dir[i].second;
                    if(row>=0 && col>=0 && row<n && col<m && grid[row][col]==0) {
                        q.push({row,col});
                        grid[row][col] = 1+grid[x][y];
                    }
                 }
        }
        return -1;
    }
};
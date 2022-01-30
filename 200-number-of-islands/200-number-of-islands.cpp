class Solution {
public:
    vector<pair<int,int>> direction{ {1,0}, {0,1},{-1,0}, {0,-1} };
    
    void bfs(vector<vector<char>> &mat,int i,int j)
    {
        mat[i][j] = '2';
        queue<pair<int,int>> q;
        q.push({i,j});
        while(q.empty()==false)
        {
            pair<int,int> old = q.front();
            q.pop();
            for(auto d: direction)
            {
                int x = old.first + d.first;
                int y = old.second + d.second;
                if((x<mat.size() && x>=0 && y<mat[0].size() && y>=0) && mat[x][y]=='1')
                {
                    mat[x][y] = '2';
                    q.push({x,y});
                }
            }
        }
    }
    int numIslands(vector<vector<char>>& grid) {
        int res = 0;
        for(int i=0; i<grid.size(); i++)
        {
            for(int j=0; j<grid[0].size(); j++)
            {
                if(grid[i][j]=='1')
                {
                    bfs(grid,i,j);
                    res++;
                }
            }
        }
        return res;
    }
};
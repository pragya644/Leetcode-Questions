class Solution {
public:
    
    vector<pair<int,int>> v = {{-1,0},{1,0},{0,1},{0,-1}};
    
    int solve(queue<pair<int,int>> &q, vector<vector<int>> &grid)
    {
        int dis =0;
        while(q.empty()==false)
        {
            int n = q.size();
            dis++;
            for(int i=0; i<n; i++)
            {
                auto temp = q.front();
                q.pop();
                for(int j=0; j<4; j++)
                {
                    int x = temp.first + v[j].first;
                    int y = temp.second + v[j].second;
                    if(x>=0&&x<grid.size()&&y>=0 && y<grid[0].size()&&grid[x][y]==0)
                    {
                        grid[x][y] = dis;
                        q.push({x,y});                                                                                            
                    }
                }
            }
        }
        return dis-1;
    }
    
    int maxDistance(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        queue<pair<int,int>> q;
        for(int i=0; i<n; i++)
        {
            for(int j=0; j<m; j++)
            {
                if(grid[i][j]==1)
                    q.push({i,j});
            }
        }
        
        if(q.size()==n*m || q.size()==0)
            return -1;
        
        return solve(q,grid);
    }
};
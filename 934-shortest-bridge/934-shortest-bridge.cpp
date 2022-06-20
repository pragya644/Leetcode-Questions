class Solution {
public:
    
    void solve(vector<vector<int>> &grid, int i, int j,queue<pair<int,int>> &q)
    {
        if(i<0 || i>=grid.size() || j<0 || j>=grid[0].size() || grid[i][j]!=1)
            return;
        grid[i][j] = 2;
        q.push({i,j});
        solve(grid,i-1,j, q);
        solve(grid,i,j-1, q);
        solve(grid,i,j+1, q);
        solve(grid,i+1,j, q);
    }
    
    int shortestBridge(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        queue<pair<int,int>> q;
        bool flag = false;
        for(int i=0; i<n; i++)
        {
            for(int j=0; j<m; j++)
            {
                if(grid[i][j]==1 && !flag)
                {
                    solve(grid,i,j,q);
                    flag = true;
                    break;
                    
                }
            }
            if(flag)
                break;
        }
        int no_of_flip = 0;
        int min_dis = INT_MAX;
        vector<pair<int,int>> dir = {{-1,0}, {1,0}, {0,1}, {0,-1}};
        while(q.empty()==false)
        {
            int size = q.size();
            for(int i=0; i<size; i++)
            {
                auto curr = q.front();
                int x = curr.first;
                int y = curr.second;
                q.pop();
                for(int i=0; i<4; i++)
                {
                    int row = x+dir[i].first;
                    int col = y+dir[i].second;
                    if(row>=0 && col>=0 && row<n && col<m)
                    {
                        if(grid[row][col]==1)
                        {
                            min_dis = min(min_dis, no_of_flip);
                        }
                        if(grid[row][col]==0)
                        {
                            grid[row][col] = 2; //visited
                            q.push({row,col});
                        }
                    }
                }
            }
            no_of_flip++;
        }
        return min_dis;
    }
};
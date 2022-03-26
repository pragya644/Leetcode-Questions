class Solution {
public:
    
    vector<int> findBall(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        vector<int> ans(n);
        for(int i=0; i<n; i++)
        {
            int row = 0, col = i;
            while(row<m)
            {
                if(grid[row][col]==1)
                {
                    if(col+1>=n || grid[row][col+1]==-1)
                    {
                        ans[i] = -1;
                        break;
                    }
                    col++;
                }
                else
                {
                    if(col-1<0 || grid[row][col-1]==1)
                    {
                        ans[i] = -1;
                        break;
                    }
                    col--;
                }
                row++;
            }
            if(row==m)
                ans[i] = col;
        }
        return ans;
    }
};
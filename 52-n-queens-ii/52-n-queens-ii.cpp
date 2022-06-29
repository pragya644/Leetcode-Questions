class Solution {
public:
    
    bool can_place(int r, int c, vector<vector<int>> &v)
    {
        int x = r;
        int y = c;
        x--;
        y--;
        while(x>=0 && y>=0)
        {
            if(v[x][y]==1)
                return false;
            x--;
            y--;
        }
        x = r;
        y = c;
        x--;
        while(x>=0)
        {
            if(v[x][y]==1)
                return false;
            x--;
        }
        x = r;
        x--;
        y++;
        while(x>=0 && y<v.size())
        {
            if(v[x][y]==1)
                return false;
            x--;
            y++;
        }
        return true;
    }
    
    void is_valid(int row, int col,int n, vector<vector<int>> &v, int &ans)
    {
        if(!can_place(row,col,v))
        {
            return;
        }
        v[row][col] = 1;
        if(row==n-1)
        {
            ans++;
            return;
        }
        for(int col=0; col<n; col++)
        {
            is_valid(row+1,col,n,v,ans);
        }
        v[row][col] = 0;
    }
    
    int totalNQueens(int n) {
        vector<vector<int>> v(n, vector<int> (n,0));
        int ans = 0;
        for(int i=0; i<n; i++)
        { 
            is_valid(0,i,n,v,ans);
        }
        return ans;
    }
};
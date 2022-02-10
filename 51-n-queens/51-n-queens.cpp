class Solution {
public:
    bool isvalid(int row,int col, vector<string> temp,int n)
    {
        int x = row, y = col;
        while(x>=0 && y>=0)
        {
            if(temp[x][y]=='Q')
                return false;
            x--;
            y--;
        }
        x = row;
        y = col;
        while(y>=0)
        {
            if(temp[x][y]=='Q')
                return false;
            y--;
        }
        y = col;
        while(x<n && y>=0)
        {
            if(temp[x][y]=='Q')
                return false;
            x++;
            y--;
        }
        return true;
    }
    
    void solve(vector<string> &temp,vector<vector<string>>&res,int n,int col)
    {
        if(col==n)
        {
            res.push_back(temp);
            return;
        }
        for(int row = 0; row<n; row++)
        {
            if(isvalid(row,col,temp,n))
            {
                temp[row][col] = 'Q';
                solve(temp,res,n,col+1);
                temp[row][col] = '.';
            }
        }
    }
    
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> res;
        vector<string> temp;
        string s(n, '.');
        for(int i=0; i<n; i++)
            temp.push_back(s);
        solve(temp,res,n,0);
        return res;
    }
};
class Solution {
public:
    
    bool isvalid(int row, int col, int n, vector<string> &temp)
    {
        int x = row, y = col;
        while(x>=0 && y>=0)
        {
            if(temp[x][y]=='Q')
                return false;
            x--;
            y--;
        }
        x = row, y = col;
        while(y>=0)
        {
            if(temp[row][y]=='Q')
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
    
    void solve(vector<string> &temp, vector<vector<string>> &res, int col,int n)
    {
        if(col==n)
        {
            res.push_back(temp);
            return;
        }
        for(int row = 0; row<n; row++)
        {
            if(isvalid(row,col, n, temp))
            {
                temp[row][col] = 'Q';
                solve(temp, res, col+1, n);
                temp[row][col] = '.';
            }
        }
    }
    
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> res;
        vector<string> temp;
        string s(n,'.');
        for(int i=0; i<n; i++)
        {
            temp.push_back(s);
        }
        solve(temp, res, 0, n);
        return res;
    }
};
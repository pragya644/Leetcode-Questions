class Solution {
public:
    
    void solve(vector<int> &row, vector<int> &col,vector<vector<int>> &mat)
    {
        int m = mat.size();
        int n = mat[0].size();
        for(int i=0; i<m; i++)
        {
            for(int j=0; j<n; j++)
            {
                if(mat[i][j]==0)
                {
                    row[i] = 1;
                    col[j] = 1;
                }
            }
        }
    }
    
    void setZeroes(vector<vector<int>>& mat) {
        int m = mat.size();
        int n = mat[0].size();
        vector<int> row(m,0);
        vector<int> col(n,0);
        solve(row,col,mat);
        for(int i=0; i<m; i++)
        {
            if(row[i]==1)
            {
                for(int j=0; j<n; j++)
                    mat[i][j] = 0;
            }
        }
        for(int j=0; j<n; j++)
        {
            if(col[j]==1)
                for(int i=0; i<m; i++)
                    mat[i][j] = 0;
        }
    }
};
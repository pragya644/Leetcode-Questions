class Solution {
public:
    void solve(vector<vector<int>> &mat)
    {
        int n = mat.size();
        int m = mat[0].size();
        for(int i=n-1; i>=0; i--)
        {
            for(int j=m-1; j>0; j--)
            {
                if(mat[i][0]==0 || mat[0][j]==0)
                    mat[i][j] = 0;
            }
        }
    }
    
    void setZeroes(vector<vector<int>>& mat) {
        int n = mat.size();
        int m = mat[0].size();
        bool row0 = false;
        for(int j=0; j<n; j++)
            if(mat[j][0]==0)
            {
                row0 = true;
                break;
            }
        for(int i=0; i<n; i++)
        {
            for(int j=1; j<m; j++)
            {
                if(mat[i][j]==0)
                {
                    mat[0][j] = 0;
                    mat[i][0] = 0;
                }
            }
        }
        solve(mat);
        if(row0 == true)
        {
            for(int i=0; i<n; i++)
                mat[i][0] = 0;
        }
    }
};
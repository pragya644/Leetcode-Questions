class Solution {
public:
    void help(vector<vector<int>> &mat)
    {
        int m = mat.size();
        int n = mat[0].size();
        for(int i=m-1; i>=0; i--)
        {
            for(int j=n-1; j>-0; j--)
            {
                if(mat[i][0]==0 || mat[0][j]==0)
                    mat[i][j] = 0;
            }
        }
    }
    
    void setZeroes(vector<vector<int>>& mat) {
        int m = mat.size();
        int n = mat[0].size();
        bool col0 = false;
        for(int i=0; i<m; i++)
        {
            if(mat[i][0]==0)
            {
                col0 = true;
                break;
            }
        }
        for(int i=0; i<m; i++)
        {
            for(int j=1; j<n; j++)
            {
                if(mat[i][j]==0)
                {
                    mat[i][0] = 0;
                    mat[0][j] = 0;
                }
            }
        }
        help(mat);
        if(col0==true)
        {
            for(int i=0; i<m; i++)
                mat[i][0] = 0;
        }
    }
};
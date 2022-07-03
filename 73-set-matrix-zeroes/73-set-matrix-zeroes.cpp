class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int n = matrix.size();
        int m = matrix[0].size();
        int isFirstRow = 1;
        for(int i=0; i<m; i++) //iterating through 1st row
        {
            if(matrix[0][i]==0)
            {
                isFirstRow = 0;
                break;
            }
        }
        for(int i=1; i<n; i++)
        {
            for(int j=0; j<m; j++)
            {
                if(matrix[i][j]==0)
                {
                    matrix[i][0] = 0;
                    matrix[0][j] = 0;
                }
            }
        }
        for(int i=n-1; i>0; i--)
        {
            for(int j=m-1; j>=0; j--)
            {
                if(matrix[i][0]==0 || matrix[0][j]==0)
                    matrix[i][j] = 0;
            }
        }
        if(isFirstRow == 0)
        {
            for(int i=0; i<m; i++)
                matrix[0][i] = 0;
        }
    }
};
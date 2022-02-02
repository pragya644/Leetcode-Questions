class Solution {
public:
    void transpose(vector<vector<int>> &mat)
    {
        int n = mat.size();
        for(int i=0; i<n; i++)
        {
            for(int j=i+1; j<n; j++)
                swap(mat[i][j],mat[j][i]);
        }
    }
    
    void rotate(vector<vector<int>>& mat) {
        transpose(mat);
        int n = mat.size();
        int left = 0;
        int right = n-1;
        while(left<right)
        {
            for(int i=0; i<n; i++)
                swap(mat[i][left],mat[i][right]);
            left++;
            right--;
        }
    }
};
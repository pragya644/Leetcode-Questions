class Solution {
public:
    
    //Time complexity is O(n^2)
    // space complexity is O(1)
    
    void rotate(vector<vector<int>>& matrix) {
        int n = matrix.size();
        int x = 0, y=0;
        
        //transpose of matrix
        while(x<n && y<n)
        {
            int r = x, c=y;
            while(r<n && c<n)
            {
                swap(matrix[r][y], matrix[x][c]);
                r++;
                c++;
            }
            x++;
            y++;
        }
        
        //swaping value of first and last column and so on
        int left = 0, right = n-1;
        while(left<right)
        {
            for(int i=0; i<n; i++)
            {
                swap(matrix[i][left], matrix[i][right]);
            }
            left++;
            right--;
        }
    }
};
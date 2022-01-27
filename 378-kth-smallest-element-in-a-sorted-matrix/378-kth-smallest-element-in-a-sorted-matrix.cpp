class Solution {
public:
    int lowest_count(vector<vector<int>> &matrix,int mid)
    {
        int n = matrix.size();
        int count = 0;
        
        for(int i=0; i<n; i++)
        {
            for(int j=n-1; j>=0; j--)
            {
                if(matrix[i][j]<=mid){
                    count += j+1; 
                     break;
                }
            }
        }
        return count;
    }
    
    int kthSmallest(vector<vector<int>>& matrix, int k) {
        int n = matrix.size();
        if(n==1)
            return matrix[n-1][n-1];
        int ans = 0;
        int l = matrix[0][0];
        int h = matrix[n-1][n-1];
        while(l<h)
        {
           int mid = ((h-l)/2)+l;
            int count = lowest_count(matrix,mid);
            if(count>=k)
                h = mid;
            else
                l = mid+1;
        }
        return l;
    }
};
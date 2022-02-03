class Solution {
public:
    bool searchMatrix(vector<vector<int>>& mat, int target) {
        int n = mat.size();
        int m = mat[0].size();
        int len = n*m;
        int low = 0, high = len-1;
        while(low<=high)
        {
            int mid = low+(high-low)/2;
            if(mat[mid/m][mid%m]==target)
                return true;
            else if(mat[mid/m][mid%m]>target)
                high = mid-1;
            else
                low = mid+1;
        }
        return false;
    }
};
class Solution {
public:
    bool searchMatrix(vector<vector<int>>& mat, int target) {
        if(mat.size()==0 || mat[0].size()==0)
            return false;
        int l=0, h=mat.size()-1;
        while(l<=h)
        {
            int mid = l+(h-l)/2;
            if(mat[mid][0]==target)
                return true;
            else if(mat[mid][0]>target)
                h = mid-1;
            else
                l = mid+1;
        }
        int row = h;
        if(row>=0){
            l = 0, h = mat[row].size()-1;
        while(l<=h)
        {
            int mid = l+(h-l)/2;
            if(mat[row][mid]==target)
                return true;
            else if(mat[row][mid]>target)
                h = mid-1;
            else
                l = mid+1;
        }
        }
        return false;
    }
};
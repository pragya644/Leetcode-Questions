class Solution {
public:
    bool searchMatrix(vector<vector<int>>& mat, int target) {
        vector<int> v;
        int n = mat.size();
        int m = mat[0].size();
        for(int i=0; i<n; i++)
        {
            for(int j=0; j<m; j++)
                v.push_back(mat[i][j]);
        }
        int len = v.size();
        int low = 0, high = len-1;
        while(low<=high)
        {
            int mid = low+(high-low)/2;
            if(v[mid]==target)
                return true;
            else if(v[mid]>target)
                high = mid-1;
            else
                low = mid+1;
        }
        return false;
    }
};
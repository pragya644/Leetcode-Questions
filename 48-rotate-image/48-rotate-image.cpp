class Solution {
public:
    void transpose(vector<vector<int>> &m)
    {
        int n = m.size();
        for(int i=0; i<n; i++)
        {
            for(int j= i+1; j<n; j++)
            {
                if(i!=j)
                    swap(m[i][j], m[j][i]);
            }
        }
    }
    
    void rotate(vector<vector<int>>& m) {
        transpose(m);
        int n = m.size();
        int left = 0;
        int right = n-1;
        while(left<right)
        {
            for(int i=0; i<n; i++)
            {
                swap(m[i][left],m[i][right]);
            }
            left++;
            right--;
        }
    }
};
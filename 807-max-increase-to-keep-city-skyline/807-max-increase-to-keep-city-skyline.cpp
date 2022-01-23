class Solution {
public:
    int maxIncreaseKeepingSkyline(vector<vector<int>>& grid) {
        vector<int> row;
        vector<int> coln;
        int n = grid.size();
        int ans = 0;
        for(int i=0; i<n; i++)
        {
            int maxir = INT_MIN;
            int maxic = INT_MIN;
            for(int j=0; j<n; j++)
            {
                if(grid[i][j]>maxir)
                    maxir = grid[i][j];
                if(grid[j][i]>maxic)
                    maxic = grid[j][i];
            }
            row.push_back(maxir);
            coln.push_back(maxic);
        }
        for(int i=0; i<n; i++)
        {
            for(int j=0; j<n; j++)
            {
                int val = min(row[i],coln[j]);
                int diff = val-grid[i][j];
                ans += diff;
                grid[i][j] = val;
            }
        }
        return ans;
    }
};
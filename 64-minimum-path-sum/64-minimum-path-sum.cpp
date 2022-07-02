class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
    
        // 1 3 1
        // 1 5 1 
        // 4 2 1
        
        // 1 4 5
        // 2 6 6
        // 6 8 7  // 7 would be the ans
        
        int row = grid.size();
        int col = grid[0].size();
        for(int i=1; i<col; i++){
            grid[0][i] += grid[0][i-1];
        }
        for(int i=1; i<row; i++){
            grid[i][0] += grid[i-1][0];
        }
        
        for(int i=1; i<row; i++){
            for(int j=1; j<col; j++){
                grid[i][j] += min(grid[i-1][j], grid[i][j-1]);
            }
        }
        return grid[row-1][col-1];
    }
};
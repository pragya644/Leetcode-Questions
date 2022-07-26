class Solution {
public:
    
    void mark(int i, int j, vector<vector<char>> & grid){
        if(i<0 || j<0 || i>=grid.size() || j>=grid[0].size() || grid[i][j]=='0')
            return;
        grid[i][j] = '0';
        mark(i+1,j,grid);
        mark(i-1,j,grid);
        mark(i,j+1,grid);
        mark(i,j-1,grid);
    }
    
    int numIslands(vector<vector<char>>& grid) {
        int noOfIsland = 0;
        int m = grid.size();
        int n = grid[0].size();
        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                if(grid[i][j]== '1'){
                    noOfIsland++;
                    mark(i,j,grid);
                }
            }
        }
        return noOfIsland;
    }
};
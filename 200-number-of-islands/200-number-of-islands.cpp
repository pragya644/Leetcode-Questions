class Solution {
public:
    
    void dfs(int i, int j, vector<vector<char>>& grid){
        if(i<0 || j<0 || i>=grid.size() || j>=grid[0].size() || grid[i][j]=='0'){
            return;
        }
        grid[i][j] = '0';
        dfs(i-1,j,grid);
        dfs(i+1,j,grid);
        dfs(i,j-1,grid);
        dfs(i,j+1,grid);
    }
    
    int numIslands(vector<vector<char>>& grid) {
        int numOfIsland = 0;
        int row = grid.size();
        int col = grid[0].size();
        for(int i=0; i<row; i++){
            for(int j=0; j<col; j++){
                if(grid[i][j] == '1'){
                    numOfIsland++;
                    dfs(i,j,grid);
                }
            }
        }
        return numOfIsland;
    }
};
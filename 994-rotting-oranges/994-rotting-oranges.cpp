class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int row = grid.size();
        int col = grid[0].size();
        
        int noOfFreshOranges = 0;
        
        queue<pair<int,int>> rottenOranges;
        for(int i=0; i<row; i++){
            for(int j=0; j<col; j++){
                if(grid[i][j]==2){
                    rottenOranges.push({i,j});
                }
                if(grid[i][j]==1){
                    noOfFreshOranges++;
                }
            }
            
        }
        
        vector<pair<int,int>> dir = {{-1,0},{0,-1},{1,0},{0,1}};
        int time = -1;
        while(rottenOranges.empty()==false){
            
            int n = rottenOranges.size();
            time++;
            for(int i=0; i<n; i++){
                auto curr = rottenOranges.front();
                rottenOranges.pop();
                int x = curr.first;
                int y = curr.second;
                for(auto it: dir){
                    int r = x+it.first;
                    int c = y+it.second;
                    if(r>=0 && c>=0 && r<row && c<col && grid[r][c]==1){
                        rottenOranges.push({r,c});
                        grid[r][c] = 2;
                        noOfFreshOranges--;
                    }
                }
            }  
        }
        if(time == -1)
            time++;
        
        if(noOfFreshOranges>0)
            return -1;
        return time;
        
    }
};
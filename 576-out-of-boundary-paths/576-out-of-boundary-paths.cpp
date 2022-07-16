class Solution {
public:
    
    // 102984580
    
    int mod = 1000000007;
    
    int dp[51][51][51];
    
    int helpFindingPath(int row,int col,int maxMove,int m,int n)
    {
        if(row<0 || col<0 || row>=m || col>=n)
        {
            return 1;
        }
        if(maxMove==0){
            return 0;
        }
         if(dp[row][col][maxMove]!=-1)
            return dp[row][col][maxMove];
        int totalPath = 0;
        totalPath = (totalPath + helpFindingPath(row-1,col,maxMove-1,m,n))%mod;
        totalPath = (totalPath + helpFindingPath(row+1,col,maxMove-1,m,n))%mod;
        totalPath = (totalPath + helpFindingPath(row,col-1,maxMove-1,m,n))%mod;
        totalPath = (totalPath + helpFindingPath(row,col+1,maxMove-1,m,n))%mod;
        dp[row][col][maxMove] = totalPath;
        return dp[row][col][maxMove];
    }
    
    int findPaths(int m, int n, int maxMove, int startRow, int startColumn) {
        memset(dp,-1,sizeof(dp));
        return helpFindingPath(startRow,startColumn,maxMove,m,n);
    }
};
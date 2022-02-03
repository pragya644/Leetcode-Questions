class Solution {
public:
    int memo[101][101];
    
    int solve(int x,int y,int m,int n)
    {
        if(memo[x][y]!=-1)
            return memo[x][y];
        if(x>=m || y>=n)
            return memo[x][y]==0;
        if(x==m-1 || y==n-1)
            return memo[x][y] = 1;
        return memo[x][y] = solve(x+1,y,m,n) + solve(x,y+1,m,n);
    }
    
    int uniquePaths(int m, int n) {
        memset(memo,-1, sizeof(memo));
        int ans = solve(0,0,m,n);
        return ans;
    }
};
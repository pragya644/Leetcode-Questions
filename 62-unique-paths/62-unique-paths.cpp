class Solution {
public:
    int memo[101][101];
    int solve(int m,int n,int x,int y)
    {
        if(memo[m][n]!=-1)
            return memo[m][n];
        if(m>=x ||n>=y)
            return memo[m][n] = 0;
        if(m==x-1 || n==y-1)
           return  memo[m][n]= 1;
        return memo[m][n] = solve(m+1,n,x,y)+solve(m,n+1,x,y);
    }
    
    int uniquePaths(int m, int n) {
        int x = m;
        int y = n;
        memset(memo,-1,sizeof(memo));
        return solve(0,0,x,y);
    }
};
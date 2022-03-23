class Solution {
public:
    int fib(int n) {
        if(n==0 || n==1)
            return n;
        int memo[n+1];
        memo[0] = 0;
        memo[1] = 1;
        for(int i=2; i<=n; i++)
            memo[i] = memo[i-2]+memo[i-1];
        return memo[n];
    }
};
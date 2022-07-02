class Solution {
public:
    
    //recursive solution  time complexity is O(n*2^min(n,k));
    // int solve(int k, int n)
    // {
    //     if(k==1)
    //         return n;
    //     if(n==0 || n==1)
    //         return n;
    //     int ans = INT_MAX;
    //     for(int i=1; i<=n; i++)
    //     {
    //         int temp = 1 + max(solve(k-1,i-1), solve(k,n-i));
    //         ans = min(ans, temp);
    //     }
    //     return ans;
    // }
    
    
    //memo binary search solution  O(n*k*logn)
    int dp[101][10001];
    int solve(int k, int n)
    {
        if(k==1)
            return n;
        if(n==0 || n==1)
            return n;
        if(dp[k][n]!=-1)
            return dp[k][n];
        int ans = INT_MAX;
        int left = 1, right = n-1; 
        while(left<=right)
        {
            int mid = left+(right-left)/2;
            int s1 = solve(k-1,mid-1);
            int s2 = solve(k,n-mid);
            int temp = 1+max(s1,s2);
            if(s1<s2)
                left = mid+1;
            else
                right = mid-1;
            ans = min(ans, temp);
        }
        return dp[k][n] = ans;
    }
    int superEggDrop(int k, int n) {
        memset(dp,-1,sizeof(dp));
        return solve(k,n);
    }
};
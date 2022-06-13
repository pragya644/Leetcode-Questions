class Solution {
public:
    int memo[201][201];
    int solve(vector<vector<int>>& t, int i, int j)
    {
        if(memo[i][j]!=-1)
            return memo[i][j];
        if(i==t.size())
            return memo[i][j] = 0;
        return memo[i][j] = min(solve(t,i+1,j), solve(t,i+1,j+1))+t[i][j];
    }
    
    int minimumTotal(vector<vector<int>>& t) {
        int n = t.size();
        memset(memo, -1, sizeof(memo));
        return solve(t,0,0);
    }
};
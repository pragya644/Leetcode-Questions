class Solution {
public:
    int dp[501][501];
    
    int solve(int i, int j, bool turn, vector<int>& piles)
    {
        if(i>j)
            return 0;
        if(dp[i][j]!=-1)
            return dp[i][j];
        if(turn)
        {
            int calc1 = solve(i+1,j,false,piles)+piles[i];
            int calc2 = solve(i, j-1, false, piles)+piles[j];
            dp[i][j] = max(calc1,calc2);
            return dp[i][j];
        }
        int calc1 = solve(i+1,j,true,piles)-piles[i];
        int calc2 = solve(i,j-1,true,piles)-piles[j];
        dp[i][j] = min(calc1,calc2);
        return dp[i][j];
    }
    
    bool stoneGame(vector<int>& piles) {
        int n = piles.size();
        bool turn = true;
        memset(dp,-1,sizeof(dp));
        return solve(0,n-1,turn,piles)>0;
    }
};
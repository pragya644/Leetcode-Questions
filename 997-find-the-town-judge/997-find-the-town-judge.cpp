class Solution {
public:
    int check(int i, vector<vector<int>> &v, int n)
    {
        for(int j=1; j<=n; j++)
        {
            if(j==i)
                continue;
            if(v[j][i]==0)
                return -1;
        }
        return i;
    }
    
    int findJudge(int n, vector<vector<int>>& trust) {
        vector<vector<int>> v(n+1,vector<int>(n+1));
        for(int i=1; i<=n; i++)
            v[i][i] = 0;
        for(int i=0; i<trust.size(); i++)
        {
            int x = trust[i][0];
            int y = trust[i][1];
            v[x][y] = 1;
        }
        for(int i=1; i<=n; i++)
        {
            int count = 0;
            for(int j=1; j<=n; j++)
            {
                if(v[i][j]==0)
                    count++;
            }
            if(count==n)
            {
                int x = check(i,v,n);
                if(x!=-1)
                    return x;
            }
        }
        return -1;
    }
};
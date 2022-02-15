class Solution {
public:
    int countPrimes(int n) {
        int ans = 0;
        vector<bool> vis(n+1, true);
        vis[0] = vis[1] = false;
        for(int i=2; i<n; i++)
        {
            if(vis[i]==true)
            {
                ans++;
                for(int j= i+i; j<n; j = j+i)
                    vis[j] = false;
            }
        }
        return ans;
    }
};
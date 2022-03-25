class Solution {
public:
    int numTeams(vector<int>& rating) {
        int n = rating.size();
        int ans = 0;
        for(int i=0; i<n; i++)
        {
            int ls = 0, lb = 0, rs = 0, rb = 0;
            for(int j=i; j>=0; j--)
            {
                if(rating[j]<rating[i])
                    ls++;
            }
            for(int j=i; j<n; j++)
            {
                if(rating[j]>rating[i])
                    rb++;
            }
            for(int j=i; j<n; j++)
            {
                if(rating[j]<rating[i])
                    rs++;
            }
            for(int j=i; j>=0; j--)
            {
                if(rating[j]>rating[i])
                    lb++;
            }
            ans += ls*rb + lb*rs;
        }
        return ans;
    }
};
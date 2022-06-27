class Solution {
public:
    int findJudge(int n, vector<vector<int>>& trust) {
        if(n==1)
            return 1;
        if(trust.size()==0)
            return -1;
        vector<vector<int>> in(n+1);
        vector<vector<int>> out(n+1);
        for(int i=0; i<trust.size(); i++)
        {
            out[trust[i][0]].push_back(trust[i][1]);
            in[trust[i][1]].push_back(trust[i][0]);
        }
        for(int i=1; i<=n; i++)
        {
            if(out[i].size()==0 && in[i].size()==n-1)
                return i;
        }
        return -1;
    }
};
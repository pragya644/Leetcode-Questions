class Solution {
public:
    void solve(vector<int> &c,int t, int i,vector<int>&temp, vector<vector<int>> &res)
    {
        if(t==0)
        {
            res.push_back(temp);
            return;
        }
        for(int j=i; j<c.size(); j++)
        {
            if(j!=i && c[j]==c[j-1])
                continue;
            if(c[j]<=t)
            {
                temp.push_back(c[j]);
                solve(c,t-c[j],j+1,temp,res);
                temp.pop_back();
            }
        }
    }
    
    vector<vector<int>> combinationSum2(vector<int>& c, int t)     
    {
        sort(c.begin(),c.end());
        vector<vector<int>> res;
        vector<int> temp;
        solve(c,t,0,temp,res);
        return res;
    }
};
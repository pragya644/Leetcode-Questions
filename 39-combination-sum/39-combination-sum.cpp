class Solution {
public:
    void solve(vector<vector<int>> &res, vector<int> &temp,int t, int i, vector<int> &c)
    {
        if(i==c.size())
        {
            if(t==0)
                res.push_back(temp);
            return;
        }
        if(c[i]<=t)
        {
            temp.push_back(c[i]);
            solve(res,temp,t-c[i],i,c);
            temp.pop_back();
        }
        solve(res,temp,t,i+1,c);
    }
    
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> ans;
        vector<int> temp;
        solve(ans,temp,target,0,candidates);
        return ans;
    }
};
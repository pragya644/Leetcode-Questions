class Solution {
public:
    void solve(vector<int> &c, int t,int i, vector<int> &temp, vector<vector<int>> &res)
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
            solve(c,t-c[i],i,temp,res);
            temp.pop_back();
        }
        solve(c,t,i+1,temp,res);
    }
    
    vector<vector<int>> combinationSum(vector<int>& candidates, int target)     {
        vector<vector<int>> res;
        vector<int> temp;
        solve(candidates, target,0,temp,res);
        return res;
    }
};
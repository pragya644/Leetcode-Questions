class Solution {
public:
    void solve(vector<int> &c, int t,int i, vector<int> &temp, vector<vector<int>> &res)
    {
        if(t==0)
        {
            res.push_back(temp);
            return;
        }
        for(int j=i; j<c.size(); j++)
        {
           if(c[j]<=t){
            temp.push_back(c[j]);
            solve(c,t-c[j],j,temp,res);
            temp.pop_back();
           }
        }
    }
    
    vector<vector<int>> combinationSum(vector<int>& candidates, int target)     {
        vector<vector<int>> res;
        vector<int> temp;
        solve(candidates, target,0,temp,res);
        return res;
    }
};
class Solution {
public:
    void solve(vector<vector<int>> &ans, vector<int>&temp, vector<int> &c, int t,int sum, int i)
    {
        if(sum>t)
            return;
        if(sum==t)
        {
            ans.push_back(temp);
            return;
        }
        for(int j=i; j<c.size(); j++)
        {
            temp.push_back(c[j]);
            sum += c[j];
            solve(ans,temp,c,t,sum,j);
            temp.pop_back();
            sum -= c[j];
        }
    }
    
    vector<vector<int>> combinationSum(vector<int>& can, int target) {
        vector<vector<int>> ans;
        vector<int> temp;
        solve(ans,temp,can,target,0,0);
        return ans;
    }
};
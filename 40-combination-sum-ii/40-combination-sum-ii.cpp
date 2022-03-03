class Solution {
public:
    void solve(vector<vector<int>> &ans, vector<int> &temp, vector<int> &c, int t, int i, int sum)
    {
        if(sum>t)
            return;
        if(sum==t)
        {
            ans.push_back(temp);
            return;
        }
        for(int j=i;  j<c.size(); j++)
        {
            if(j!=i && c[j]==c[j-1])
                continue;
            temp.push_back(c[j]);
            sum += c[j];
            solve(ans,temp,c,t,j+1,sum);
            sum -= c[j];
            temp.pop_back();
        }
    }
    
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
        vector<vector<int>> ans;
        vector<int> temp;
        solve(ans,temp,candidates,target,0,0);
        return ans;
    }
};
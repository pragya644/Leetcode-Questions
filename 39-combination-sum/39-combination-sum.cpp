class Solution {
public:
    
    //time complexity is O(2^t*k), t is target and k is average length
    void solve(int i,int &sum, vector<int> &c,vector<int> &temp, vector<vector<int>> &ans, int target)
    {
        if(sum==target)
        {
            ans.push_back(temp);
            return;
        }
        if(sum>target)
            return;
        if(i==c.size())
            return;
        for(int j=i; j<c.size(); j++)
        {
            sum += c[j];
            temp.push_back(c[j]);
            solve(j,sum,c,temp,ans,target);
            sum -= c[j];
            temp.pop_back();
        }
    }
    
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> ans;
        vector<int> temp;
        int sum = 0;
        solve(0,sum,candidates,temp,ans,target);
        return ans;
    }
};
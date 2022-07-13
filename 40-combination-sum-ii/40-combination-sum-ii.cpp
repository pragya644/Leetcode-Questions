class Solution {
public:
    
    //time complexity is O(2^n*n)
    void solve(int i,int &sum,int target,vector<int> &temp,vector<int> &c,vector<vector<int>> &ans)
    {
        if(sum==target)
        {
            ans.push_back(temp);
            return;
        }
        if(sum>target || i==c.size())
            return;
        for(int j=i; j<c.size(); j++)
        {
            if(j!=i && c[j]==c[j-1])
                continue;
            sum += c[j];
            temp.push_back(c[j]);
            solve(j+1,sum,target,temp,c,ans);
            sum -= c[j];
            temp.pop_back();
        }
    }
    
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
        vector<vector<int>> ans;
        vector<int> temp;
        int sum = 0;
        solve(0,sum,target,temp,candidates,ans);
        return ans;
    }
};
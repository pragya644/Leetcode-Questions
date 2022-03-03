class Solution {
public:
    void solve(vector<vector<int>> &ans, vector<int> &temp, int n, int k, int i)
    {
        if(temp.size()==k)
        {
            ans.push_back(temp);
            return;
        }
        for(int j=i; j<n; j++)
        {
            temp.push_back(j+1);
            solve(ans,temp,n,k,j+1);
            temp.pop_back();
        }
    }
    
    vector<vector<int>> combine(int n, int k) {
        vector<vector<int>> ans;
        if(n<k)
            return ans;
        vector<int> temp;
        solve(ans,temp,n,k,0);
        return ans;
    }
};
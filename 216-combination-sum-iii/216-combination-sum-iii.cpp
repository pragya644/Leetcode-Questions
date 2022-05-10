class Solution {
public:
    void solve(int k, int n, int no, vector<int> &temp, vector<vector<int>> &ans)
    {
        if(k==0 && n==0){
            ans.push_back(temp);
            return;
        }
        if(k<0 || n<0)
            return;
        for(int i=no; i<=9; i++)
        {
            if(n-i>=0)
            {
                temp.push_back(i);
                solve(k-1,n-i,i+1,temp,ans);
                temp.pop_back();
            }
        }
    }
    
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<vector<int>> ans;
        vector<int> temp;
        solve(k,n,1,temp,ans);
        return ans;
    }
};
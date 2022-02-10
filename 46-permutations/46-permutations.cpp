class Solution {
public:
    void solve(vector<int> &nums,vector<int> &vis,vector<int>&temp, vector<vector<int>> &res)
    {
        if(temp.size()==nums.size())
        {
            res.push_back(temp);
            return;
        }
        for(int j=0; j<nums.size(); j++)
        {
            if(vis[j]==0)
            {
                temp.push_back(nums[j]);
                vis[j] = 1;
                solve(nums,vis,temp,res);
                vis[j] = 0;
                temp.pop_back();
            }
        }
    }
    
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> res;
        vector<int> temp;
        int n = nums.size();
        vector<int> vis(n,0);
        solve(nums,vis,temp,res);
        return res;
    }
};
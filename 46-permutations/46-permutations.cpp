class Solution {
public:
    void solve(vector<vector<int>> &ans, vector<int> &temp, vector<int> &nums, vector<bool> &vis)
    {
        if(temp.size()==nums.size())
        {
            ans.push_back(temp);
            return;
        }
        for(int j=0; j<nums.size(); j++)
        {
            if(vis[j]==false)
            {
                vis[j] = true;
                temp.push_back(nums[j]);
                solve(ans, temp, nums, vis);
                vis[j] = false;
                temp.pop_back();
            }
        }
    }
    
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> temp;
        int n = nums.size();
        vector<bool> vis(n, false);
        solve(ans, temp,nums, vis);
        return ans;
    }
};
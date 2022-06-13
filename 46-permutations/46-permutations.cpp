class Solution {
public:
    void solve(vector<vector<int>>&ans, vector<int>&temp, vector<bool>&vis, vector<int> &nums, int k)
    {
        if(k==nums.size())
        {
            ans.push_back(temp);
            return;
        }
        for(int i=0; i<nums.size(); i++)
        {
            if(vis[i]==false)
            {
                temp.push_back(nums[i]);
                vis[i] = true;
                solve(ans,temp, vis, nums, k+1);
                vis[i] = false;
                temp.pop_back();
            }
        }
    }
    
    vector<vector<int>> permute(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>> ans;
        vector<int> temp;
        vector<bool> vis(n, false);
        solve(ans,temp,vis,nums,0);
        return ans;
    }
};
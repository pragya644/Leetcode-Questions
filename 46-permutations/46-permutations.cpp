class Solution {
public:
    
    //time complexity O(n*n!)
    
    void solve(vector<int> &temp, vector<vector<int>> &ans, vector<bool> &vis, vector<int> &nums)
    {
        if(temp.size()==nums.size())
        {
            ans.push_back(temp);
            return;
        }
        // vis[i] = true;
        for(int j=0; j<nums.size(); j++)
        {
            if(vis[j]==false)
            {
                temp.push_back(nums[j]);
                vis[j] = true;
                solve(temp,ans,vis,nums);
                temp.pop_back();
                vis[j] = false;
            }
        }
    }
    
    vector<vector<int>> permute(vector<int>& nums) {
        int n = nums.size();
        vector<int> temp;
        vector<vector<int>> ans;
        vector<bool> vis(n,false);
        solve(temp,ans,vis,nums);
        return ans;
    }
};
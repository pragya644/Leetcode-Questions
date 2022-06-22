class Solution {
public:
    void solve(vector<vector<int>> &nums, int i, vector<bool> &vis)
    {
        vis[i] = true;
        for(int j=0; j<nums.size(); j++)
        {
            if(vis[j]==false && nums[i][j]==1) 
            {
                solve(nums,j,vis);
            }
        }
    }
    
    int findCircleNum(vector<vector<int>>& nums) {
        int n = nums.size();
        vector<bool> vis(n,false);
        int ans = 0;
        for(int i=0; i<n; i++)
        {
            if(vis[i]==false)
            {
                ans++;
                solve(nums,i,vis);
            }
        }
        return ans;
    }
};
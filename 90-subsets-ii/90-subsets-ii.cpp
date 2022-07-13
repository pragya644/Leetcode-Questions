class Solution {
public:
    
    void solve(int i,vector<int>&temp,vector<vector<int>> &ans,vector<int>&nums)
    {
        ans.push_back(temp);
        if(i==nums.size())
            return;
        for(int j=i; j<nums.size(); j++)
        {
            if(j!=i && nums[j]==nums[j-1])
                continue;
            temp.push_back(nums[j]);
            solve(j+1,temp,ans,nums);
            temp.pop_back();
        }
    }
    
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<vector<int>> ans;
        vector<int> temp;
        solve(0,temp,ans,nums);
        return ans;
    }
};
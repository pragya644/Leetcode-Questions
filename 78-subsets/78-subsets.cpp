class Solution {
public:
    void solve(vector<vector<int>> &ans, vector<int> &temp, int i, vector<int> nums)
    {
        if(i>nums.size())
            return;
        ans.push_back(temp);
        for(int j=i; j<nums.size(); j++)
        {
            temp.push_back(nums[j]);
            solve(ans,temp,j+1,nums);
            temp.pop_back();
        }
    }
    
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> temp;
        solve(ans, temp, 0, nums);
        return ans;
    }
};
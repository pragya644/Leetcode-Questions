class Solution {
public:
    void solve(vector<vector<int>> &ans, vector<int> &temp, int i, vector<int> &nums)
    {
        if(i>nums.size())
        {
            return;
        }
        ans.push_back(temp);
        for(int j=i; j<nums.size(); j++)
        {
            if(j!=i && nums[j]==nums[j-1])
                continue;
            temp.push_back(nums[j]);
            solve(ans, temp, j+1, nums);
            temp.pop_back();
        }
    }
    
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<vector<int>> ans;
        vector<int> temp;
        solve(ans, temp, 0, nums);
        return ans;
    }
};
class Solution {
public:
    void solve(vector<vector<int>> &ans, vector<int> &nums, int i)
    {
        if(i==nums.size())
        {
            ans.push_back(nums);
            return;
        }
        unordered_set<int> s;
        for(int j=i; j<nums.size(); j++)
        {
            if(s.find(nums[j])!=s.end())
                continue;
            s.insert(nums[j]);
            swap(nums[i], nums[j]);
            solve(ans,nums,i+1);
            swap(nums[i], nums[j]);
        }
    }
    
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>> ans;
        solve(ans,nums,0);
        return ans;
    }
};
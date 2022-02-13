class Solution {
public:
    void solve(vector<int> &nums, vector<int> &temp, int i, vector<vector<int>> &res)
    {
        if(i==nums.size())
        {
            res.push_back(temp);
            return;
        }
        temp.push_back(nums[i]);
        solve(nums, temp, i+1, res);
        temp.pop_back();
        solve(nums, temp, i+1, res );
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<int> temp;
        vector<vector<int>> res;
        solve(nums,temp,0,res);
        return res;
    }
};
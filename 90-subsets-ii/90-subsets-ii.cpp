class Solution {
public:
    void backtracking(vector<int> &nums, int i, vector<int> &temp, vector<vector<int>> &res)
    {
        res.push_back(temp);
        for(int j=i; j<nums.size(); j++)
        {
            if(j!=i && nums[j]==nums[j-1])
                continue;
            temp.push_back(nums[j]);
            backtracking(nums,j+1,temp,res);
            temp.pop_back();
        }
    }
    
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<vector<int>> res;
        vector<int> temp;
        backtracking(nums,0,temp,res);
        return res;
    }
};
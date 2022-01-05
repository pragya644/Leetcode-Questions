class Solution {
public:
    void rec(vector<int> &nums, vector<int> &temp,int i,vector<vector<int>>&ans)
    {
        if(i==nums.size())
            ans.push_back(temp);
        else
        {
            temp.push_back(nums[i]);
            rec(nums,temp,i+1,ans);
            temp.pop_back();
            rec(nums,temp,i+1,ans);
        }
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<int> temp;
        vector<vector<int>> res;
        rec(nums,temp,0,res);
        return res;
    }
};
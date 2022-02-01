class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int n = nums.size();
        int res = nums[0];
        for(int i=1; i<n; i++)
        {
            nums[i] = max(nums[i], nums[i]+nums[i-1]);
            res = max(res,nums[i]);
        }
        return res;
    }
};
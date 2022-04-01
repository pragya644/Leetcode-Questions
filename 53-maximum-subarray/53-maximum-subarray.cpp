class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int n = nums.size();
        int maxi = nums[0];
        for(int i=1; i<n; i++)
        {
            nums[i] = max(nums[i], nums[i-1]+nums[i]);
            maxi = max(maxi, nums[i]);
        }
        return maxi;
    }
};
class Solution {
public:
    
    // -2 1 -3 4 -1 2 1 -5 4
    // -2 1 -2 4  3 5 6  1 5
    
    //time compexity O(n);
    
    int maxSubArray(vector<int>& nums) {
        int n = nums.size();
        int ans = nums[0];
        for(int i=1; i<n; i++)
        {
            nums[i] = max(nums[i], nums[i]+nums[i-1]);
            ans = max(ans, nums[i]);
        }
        return ans;
    }
};
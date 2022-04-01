class Solution {
public:
    int maxSubarraySumCircular(vector<int>& nums) {
        int n = nums.size();
        int maxsum = nums[0];
        int minsum = nums[0];
        int currmax = nums[0];
        int currmin = nums[0];
        int sum = nums[0];
        for(int i=1; i<n; i++)
        {
            sum += nums[i];
            currmax = max(currmax+nums[i], nums[i]);
            maxsum = max(maxsum, currmax);
            currmin = min(currmin+nums[i], nums[i]);
            minsum = min(minsum, currmin);
        }
        if(minsum==sum)
            return maxsum;
        return max(maxsum, sum-minsum);
        
    }
};
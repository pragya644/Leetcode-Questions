class Solution {
public:
    bool canJump(vector<int>& nums) {
        int n = nums.size();
        int maxjump = 0;
        for(int i=n-2; i>=0; i--)
        {
            maxjump++;
            if(nums[i]>=maxjump)
            {
                maxjump = 0;
            }
        }
        if(maxjump==0)
            return true;
        return false;
    }
};
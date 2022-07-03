class Solution {
public:
    int wiggleMaxLength(vector<int>& nums) {
        int n = nums.size();
        if(n==0)
            return 0;
        int pos = 1, neg = 1;
        for(int i=1; i<n; i++)
        {
            if(nums[i]>nums[i-1])
                pos = neg+1;
            else if(nums[i]<nums[i-1])
                neg = pos+1;
        }
        return max(pos,neg);
    }
};
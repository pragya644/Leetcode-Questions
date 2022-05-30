class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        vector<int> length(n,1);
        int maxi = 1;
        for(int i=1; i<n; i++)
        {
            for(int j=0; j<i; j++)
            {
                if(nums[j]<nums[i])
                {
                    length[i] = max(length[i], length[j]+1);
                    maxi = max(length[i], maxi);
                }
            }
        }
        return maxi;
    }
};
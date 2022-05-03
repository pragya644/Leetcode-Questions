class Solution {
public:
    int findUnsortedSubarray(vector<int>& nums) {
        int n =  nums.size();
        int s=-1,e=-1;
        int curr_max = INT_MIN;
        for(int i=0; i<n; i++)
        {
            if(curr_max<nums[i]) 
                curr_max = nums[i];
            if(nums[i]<curr_max)
                e = i;
        }
        int curr_min = INT_MAX;
        for(int i=n-1; i>=0; i--)
        {
            if(curr_min > nums[i])
                curr_min = nums[i];
            if(nums[i]>curr_min)
                s = i;
        }
        if(s==-1)
             return 0;
        else
            return e-s+1;
    }
};
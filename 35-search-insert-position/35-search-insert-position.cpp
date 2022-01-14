class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int n = nums.size();
        int l = 0;
        int r = n-1;
        while(l<r)
        {
            int mid = (r+l)/2;
            if(nums[mid]==target)
                return mid;
            else if(nums[mid]<target)
                l = mid+1;
            else
                r = mid-1; 
        }
        int ans;
        if(nums[l]<target)
           ans = l+1;
        else
            ans = l;
        return ans;
    }
};
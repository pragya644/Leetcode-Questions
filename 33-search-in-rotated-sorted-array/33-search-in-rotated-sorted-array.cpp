class Solution {
public:
    int search(vector<int>& nums, int target) {
        int n = nums.size();
        int l =0, h = n-1;
        while(l<h)
        {
            int mid = (l+h)/2;
            if(nums[mid]>nums[h])
                l = mid+1;
            else
                h = mid;
        }
        int rotation = l;
        l = 0, h = n-1;
        while(l<=h)
        {
            int mid = (l+h)/2;
            int realmid = (mid+rotation)%n;
            if(nums[realmid]==target)
                return realmid;
            else if(nums[realmid]>target)
                h = mid-1;
            else
                l = mid+1;
        }
        return -1;
    }
};
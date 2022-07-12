class Solution {
public:
    
    int solve(int l, int r, vector<int> &nums)
    {
        int n = nums.size();
        int pivot = nums[r];
        int p = l-1;
        for(int j=l; j<r; j++)
        {
            if(nums[j]<pivot)
            {
                p++;
                swap(nums[p], nums[j]);
            }
        }
        swap(nums[p+1], nums[r]);
        return p+1;
    }
    
    int findKthLargest(vector<int>& nums, int k) {
        int n = nums.size();
        k = n-k;
        int l = 0, r = n-1;
        while(l<=r)
        {
            int idx = solve(l,r,nums);
            if(idx==k)
                return nums[idx];
            if(idx>k)
                r = idx-1;
            else
                l = idx+1;
        }
        return -1;
    }
};
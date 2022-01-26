class Solution {
public:
    int partition(vector<int> &nums, int l, int r)
    {
        int pivot = nums[r];
        int i = l-1;
        for(int j=l; j<r; j++)
        {
            if(nums[j]<pivot)
            {
                i++;
                swap(nums[i],nums[j]);
            }
        }
        swap(nums[i+1],nums[r]);
        return i+1;
    }
    
    int findKthLargest(vector<int>& nums, int k) {
        k = nums.size()-k;
        int l = 0,r = nums.size()-1;
        int ans=0;
        while(true)
        {
            int idx = partition(nums,l,r);
            if(idx==k)
            {
                ans = nums[idx];
                break;
            }
            if(idx<k)
                l = idx+1;
            if(idx>k)
                r = idx-1;
        }
        return ans;
    }
};
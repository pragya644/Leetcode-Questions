class Solution {
public:
    int solve(int l, int r, vector<int> &nums)
    {
        int p = nums[r];
        int i=l-1;
        for(int k=l; k<r; k++)
        {
            if(nums[k]<p)
            {
                i++;
                swap(nums[i], nums[k]);
            }
        }
        swap(nums[i+1], nums[r]);
        return i+1;
    }
    
    int findKthLargest(vector<int>& nums, int k) {
        int n = nums.size();
        k = n-k;
        int ans = 0;
        int l = 0, r = n-1;
        while(true)
        {
            int i = solve(l,r,nums);
            if(i==k)
            {
                ans = nums[i];
                break;
            }
            else if(i<k)
                l = i+1;
            else
                r = i-1;
        }
        return ans;
    }
};
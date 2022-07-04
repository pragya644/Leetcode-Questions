class Solution {
public:
    
    //binary search solution
    int findDuplicate(vector<int>& nums) {
        int n = nums.size()-1;
        int l = 0, r = n;
        while(l<r)
        {
            int mid = l+(r-l)/2;
            int count = 0;
            for(int i=0; i<=n; i++)
            {
                if(nums[i]<=mid)
                    count++;
            }
            if(count>mid)
                r = mid;
            else
                l = mid+1;
        }
        return l;
    }
};
class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        int ans ;
        int minDiff = INT_MAX;
        for(int i=0; i<n-2; i++)
        {
            int l = i+1;
            int r = n-1;
            while(l<r)
            {
                int sum = nums[l]+nums[r]+nums[i];
                int diff = abs(target-sum);
                if(diff<minDiff)
                {
                    minDiff = diff;;
                    ans = sum;
                }
                if(sum>target)
                    r--;
                else if(sum<target)
                    l++;
                else if(sum==target)
                    return ans;
            }
        }
        return ans;
    }
};
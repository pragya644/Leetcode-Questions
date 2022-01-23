class Solution {
public:
    int minPairSum(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        int l = 0;
        int r = n-1;
        int ans = INT_MIN;
        while(l<r)
        {
            int sum = nums[l]+nums[r];
            ans = max(ans,sum);
            l++;
            r--;
        }
        return ans;
    }
};
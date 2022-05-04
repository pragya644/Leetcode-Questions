class Solution {
public:
    int maxOperations(vector<int>& nums, int k) {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        int s=0, e=n-1;
        int ans = 0;
        while(s<e)
        {
            int sum = nums[s]+nums[e];
            if(sum == k)
            {
                ans++;
                s++;
                e--;
            }
            else if(sum > k)
                e--;
            else
                s++;
        }
        return ans;
    }
};
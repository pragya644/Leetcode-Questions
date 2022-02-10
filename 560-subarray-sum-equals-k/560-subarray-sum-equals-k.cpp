class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        unordered_map<int,int> m;
        int presum = 0;
        int n = nums.size();
        m[0]++;
        int ans = 0;
        for(int i=0; i<n; i++)
        {
            presum += nums[i];
            ans = ans + m[presum-k];
            m[presum]++;
        }
        return ans;
    }
};
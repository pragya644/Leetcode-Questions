class Solution {
public:
    int solve(vector<int>&nums, int k)
    {
        int n = nums.size();
        vector<int> v(n+1,0);
        int j=0;
        int ans = 0;
        for(int i=0; i<n; i++)
        {
            int x = nums[i];
            v[x]++;
            if(v[x]==1)
                k--;
            while(k<0)
            {
                v[nums[j]]--;
                if(v[nums[j]]==0)
                    k++;
                j++;
            }
            ans+= i-j+1;
        }
        return ans;
    }
    
    int subarraysWithKDistinct(vector<int>& nums, int k) {
        return solve(nums,k)-solve(nums,k-1);
    }
};
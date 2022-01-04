class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        if(nums.empty())
            return {};
        vector<vector<int>> res;
        int n = nums.size();
        if(n<3)
            return {};
        sort(nums.begin(),nums.end());
        for(int i=0; i<n-2; i++)
        {
            if(i>0 && nums[i]==nums[i-1])
                continue;
            int a = nums[i], l= i+1, r= n-1;
            while(l<r)
            {
                int diff = nums[l] + nums[r];
                int sum = 0 - a;
                if(diff== sum)
                {
                    res.push_back({a,nums[l],nums[r]});
                    int left = nums[l];
                    int right = nums[r];
                    while(l<r && left==nums[l])
                    {
                        l++;
                    }
                    while(l<r && right==nums[r])
                    {
                        r--;
                    }
                }
                else if(diff < sum)
                    l++;
                else
                    r--;
            }
        }
        return res;
    }
};
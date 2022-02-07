class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        int n = nums.size();
        if(n<3 || n==0)
            return {};
        vector<vector<int>> res;
        sort(nums.begin(), nums.end());
        for(int i=0; i<n-2; i++)
        {
            // -1 -1 0 1 2 4 4
            //  f  l         r
            //  0-f = 0-(-1) = 1;
            //  l+r = -1 + 4 = 3;  half_sum>left_sum
            //       l   r 
            if(i>0 && nums[i]==nums[i-1])
                continue;
            int left = i+1;
            int right = n-1;
            int first = nums[i];
            while(left<right)
            {
                // -2 + 3 -1 = 0
                // -2 + 3 = 0 - (-1);
                //  l + r =  0 -  f
                
                int half_sum = nums[left] + nums[right];
                int left_sum = 0 - first;
                if(half_sum == left_sum)
                {
                    res.push_back({first, nums[left], nums[right]});
                    left++;
                    right--;
                    while( left<right && nums[left]==nums[left-1])
                        left++;
                    while( left<right && nums[right]==nums[right+1])
                        right--;
                }
                else if(half_sum< left_sum)
                    left++;
                else
                    right--;
            }
        }
        return res;
    }
};
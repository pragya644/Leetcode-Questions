class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        vector<vector<int>> ans;
        for(int i=0; i<=n-3; i++)
        {
            if(i>0 && nums[i]==nums[i-1])
                continue;
            int left = i+1;
            int right = n-1;
            while(left<right)
            {
                int leftRightSum = nums[left]+nums[right];
                int totalSum = leftRightSum + nums[i];
                if(totalSum == 0){
                    ans.push_back({nums[i],nums[left], nums[right]});
                    left++;
                    right--;
                    while(left<right && nums[left]==nums[left-1]) left++;
                    while(left<right && nums[right]==nums[right+1]) right--;
                } else if(totalSum < 0){
                    left++;
                }else{
                    right--;
                }
            }
        }
        return ans;
    }
};
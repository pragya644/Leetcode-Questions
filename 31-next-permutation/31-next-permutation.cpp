class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int next_idx = -1;
        int greater_idx = -1;
        int n = nums.size();
        for(int i=n-1; i>0; i--)
        {
            if(nums[i]>nums[i-1])
            {
                next_idx= i-1;
                break;
            }
        }
        if(next_idx<0)
        {
            sort(nums.begin(),nums.end());
            return;
        }
        for(int i=n-1; i>=0; i--)
        {
            if(nums[i]>nums[next_idx])
            {
                greater_idx = i;
                break;
            }
        }
        swap(nums[next_idx],nums[greater_idx]);
        sort(nums.begin()+next_idx+1,nums.end());
    }
    
};
class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        if(nums.size()==0)
            return 0;
        int x = 1;
        int n = nums.size();
        int i=1;
        while(i<n)
        {
            if(nums[i]==nums[i-1])
                i++;
            else
            {
                nums[x] = nums[i];
                x++;
                i++;
            }
        }
        return x;
    }
};
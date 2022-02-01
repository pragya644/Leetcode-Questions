class Solution {
public:
    void sortColors(vector<int>& nums) {
        int count_0 = 0, count_1 = 0, count_2 = 0;
        int n = nums.size();
        for(int i=0; i<n; i++)
        {
            if(nums[i]==0)
                count_0++;
            else if(nums[i]==1)
                count_1++;
            else
                count_2++;
        }
        int idx = 0;
            while(count_0>0)
            {
                nums[idx] = 0;
                count_0--;
                idx++;
            }
            while(count_1>0)
            {
                nums[idx] = 1;
                count_1--;
                idx++;
            }
            while(count_2>0)
            {
                nums[idx] = 2;
                count_2--;
                idx++;
            }
    }
};
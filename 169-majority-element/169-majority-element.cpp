class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int n = nums.size();
        int count = 1;
        int temp = nums[0];
        for(int i=1; i<n; i++)
        {
            if(count==0)
            {
                temp = nums[i];
                count++;
            }
            else if(nums[i]==temp)
                count++;
            else
                count--;
        }
        return temp;
    }
};
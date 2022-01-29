class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
        int n = nums.size();
        vector<int> result(n,0);
        int positive = 0;
        int negative = 1;
        for(int i=0; i<nums.size(); i++)
        {
            if(nums[i]>0)
            {
                result[positive] = nums[i];
                positive = positive + 2;
            }
            else
            {
                result[negative] = nums[i];
                negative = negative + 2;
            }
        }
        return result;
    }
};
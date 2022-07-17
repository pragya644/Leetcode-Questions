class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        if(nums.size()==0)
            return 0;
        int uniqueNum = 1;
        int currIdx = 0;
        for(int i=1; i<nums.size(); i++)
        {
            if(nums[i]!=nums[i-1])
            {
                currIdx++;
                uniqueNum++;
                nums[currIdx] = nums[i];
            }
        }
        return uniqueNum;
    }
};
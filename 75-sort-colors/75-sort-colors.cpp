class Solution {
public:
    
    // // 2 0 2 1 1 0
    //    left = -1  right = n  mid = 0;
    //    right--
    // // 0 0 2 1  1 2 , right = n-1;
    // // if mid
    
    // time complexity is O(n)
    
    void sortColors(vector<int>& nums) {
        int size = nums.size();
        int left = -1;
        int right = size;
        int mid = 0;
        while(mid<right)
        {
            if(nums[mid]==0)
            {
                left++;
                swap(nums[left], nums[mid]);
                mid++;
            }
            else if(nums[mid]==2)
            {
                right--;
                swap(nums[mid], nums[right]);
            }
            else
            {
                mid++;
            }
        }
    }
};
class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int n = nums.size();
        int l=0, r=n-1;
        int start = -2;
        int end = 0;
        while(l<=r){
            int mid = l+(r-l)/2;
            if(nums[mid]==target){
                start = mid-1;
                end = mid+1;
                while(start>=0 && nums[start]==target)
                    start--;
                while(end<n && nums[end]==target)
                    end++;
                break;
            }else if(nums[mid]<target)
            {
                l = mid+1;
            }else{
                r = mid-1;
            }
        }
        start++;
        end--;
        return {start,end};
    }
};
class Solution {
public:
    int majorityElement(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        int low = 0;
        int high = n-1;
        int mid = (low+high)/2;
        return nums[mid];
    }
};
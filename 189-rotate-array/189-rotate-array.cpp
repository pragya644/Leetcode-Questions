class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        int n = nums.size();
        k = k%n;
        int diff = n-k;
        reverse(nums.begin(), nums.begin()+diff);
        reverse(nums.begin()+diff, nums.end());
        reverse(nums.begin(), nums.end());
    }
};
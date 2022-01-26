class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
        int begin = 1;
        int last = 1;
        vector<int> res(n,1);
        for(int i=0; i<n; i++)
        {
            res[i] = res[i]*begin;
            begin*= nums[i];
            res[n-i-1] = res[n-i-1]*last;
            last*= nums[n-i-1];
        }
        return res;
    }
};
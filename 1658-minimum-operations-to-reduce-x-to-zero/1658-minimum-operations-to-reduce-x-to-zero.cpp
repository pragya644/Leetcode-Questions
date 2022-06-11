class Solution {
public:
    int minOperations(vector<int>& nums, int x) {
        int n = nums.size();
        int sum = 0;
        for(int i=0; i<n; i++)
            sum += nums[i];
        if(sum == x)
            return n;
        if(sum<x)
            return -1;
        int find_sum = sum-x;
        int temp_sum = 0;
        int left=0, right = 0;
        int len = 0;
        while(right<n)
        {
            temp_sum += nums[right];
            while(left<n && temp_sum>find_sum)
            {
                temp_sum -= nums[left];
                left++;
            }
            if(temp_sum == find_sum)
                len = max(len, right-left+1);
            right++;
        }
        if(len==0)
            return -1;
        return n-len;
    }
};
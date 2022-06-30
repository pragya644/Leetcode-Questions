class Solution {
public:
    int minMoves2(vector<int>& nums) {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        int l = 0 , r = n-1;
        int mid = l+(r-l)/2;
        int ans = 0;
        for(int i=0; i<n; i++)
        {
            if(i!= mid)
            {
                int req = abs(nums[mid]-nums[i]);
                ans += req;
            }
        }
        return ans;
    }
};
class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int n = nums.size();
        int maxi = 1;
        int res = INT_MIN;
        for(int i=0; i<n; i++)
        {
            maxi = maxi*nums[i];
            res = max(res,maxi);
            if(maxi==0)
                maxi = 1;
        }
        
        maxi = 1;
        for(int i=n-1; i>=0; i--)
        {
            maxi = maxi*nums[i];
            res = max(maxi, res);
            if(maxi==0)
                maxi = 1;
        }
        return res;
    }
};
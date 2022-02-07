class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size();
        vector<int> left(n,0);
        vector<int> right(n,0);
        int maxi = INT_MIN;
        for(int i=0; i<n; i++)
        {
            maxi = max(maxi,height[i]);
            left[i] = maxi;
        }
        maxi = INT_MIN;
        for(int i=n-1; i>=0; i--)
        {
            maxi = max(maxi, height[i]);
            right[i] = maxi;
        }
        int ans = 0;
        for(int i=0; i<n; i++)
        {
            int x = min(left[i], right[i]);
            ans = ans + (x-height[i]);
        }
        return ans;
    }
};
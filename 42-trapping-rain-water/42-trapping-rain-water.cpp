class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size();
        if(n<3)
            return 0;
        int left = 0;
        int right = n-1;
        int ans = 0;
        int leftmax = height[0], rightmax = height[n-1];
        while(left<=right)
        {
            // if(height[left]<=height[right])
            if(leftmax<=rightmax)
            {
                if(height[left]<leftmax)
                    ans = ans + (leftmax-height[left]);
                else
                    leftmax = max(leftmax, height[left]);
                left++;
            }
            else
            {
                if(height[right]<rightmax)
                    ans = ans + (rightmax-height[right]);
                else
                    rightmax= max(rightmax, height[right]);
                right--;
            }
        }
        return ans;
    }
};
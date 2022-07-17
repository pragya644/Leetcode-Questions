class Solution {
public:
    int trap(vector<int>& height) {
        int totalWaterTrap = 0;
        int noOfBar = height.size();
        if(noOfBar<3)
            return 0;
        int left = 0;
        int right = noOfBar-1;
        int leftMax = height[left] ;
        int rightMax = height[right];
        
        while(left<=right)
        {
            if(leftMax<=rightMax){
                if(height[left]<leftMax){
                    totalWaterTrap = totalWaterTrap + (leftMax-height[left]);
                } else {
                    leftMax = max(leftMax,height[left]);
                }
                left++;
            } else{
                if(height[right]<rightMax){
                    totalWaterTrap = totalWaterTrap + (rightMax-height[right]);
                } else{
                    rightMax = height[right];
                }
                right--;
            }
        }
        return totalWaterTrap;
    }
};
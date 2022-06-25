class Solution {
public:
    bool checkPossibility(vector<int>& nums) {
        int n = nums.size();
        bool flag = false;
        for(int i=1; i<n; i++){
            if(nums[i-1]<=nums[i]){
                continue;
            }
            if(flag==false){
                if(i-2<0 || nums[i-2]<=nums[i])
                    nums[i-1] = nums[i];
                else
                    nums[i] = nums[i-1];
                flag = true;
            }
            else
                return false;
        }
        return true;
    }
};
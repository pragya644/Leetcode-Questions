class Solution {
public:
    
    int memo[1001];
    
    int sumEqualToTarget(vector<int>& nums,int target){
        if(target<0){
            return 0;
        }
        if(target==0){
            return 1;
        }
        if(memo[target]!=-1)
            return memo[target];
        int res = 0;
        for(int j=0; j<nums.size(); j++){
            target -= nums[j];
            res += sumEqualToTarget(nums,target);
            target += nums[j];
        }
        return memo[target] = res;
    }
    
    int combinationSum4(vector<int>& nums, int target) {
        int n = nums.size();
        memset(memo,-1,sizeof(memo));
        return sumEqualToTarget(nums,target);
    }
};
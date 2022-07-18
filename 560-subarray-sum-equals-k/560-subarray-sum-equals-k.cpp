class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int sizeOfArray = nums.size();
        unordered_map<int,int> storingPreSumCount;
        storingPreSumCount[0]++; // 0 sum will always exist;
        int totalSubarraysOfSumK = 0;
        int preSum = 0;
        for(int i=0; i<sizeOfArray; i++){
            preSum += nums[i];
            totalSubarraysOfSumK += storingPreSumCount[preSum-k];
            storingPreSumCount[preSum]++;
        }
        return totalSubarraysOfSumK;
    }
};
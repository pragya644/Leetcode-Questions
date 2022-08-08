class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int noOfElements = nums.size();
        vector<int> subsequence(noOfElements,1);
        int longestSubsequence = 1;
        for(int i=1; i<noOfElements; i++){
            int j=i-1;
            while(j>=0){
                if(nums[j]<nums[i]){
                    subsequence[i] = max(subsequence[i], subsequence[j]+1);
                }
                j--;
            }
            longestSubsequence = max(longestSubsequence, subsequence[i]);
        }
        return longestSubsequence;
    }
};
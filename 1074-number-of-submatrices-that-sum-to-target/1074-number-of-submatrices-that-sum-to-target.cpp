class Solution {
public:
    
    int findSubarray(vector<int> &rowSum, int target){
        unordered_map<int,int> storingPrefixSum;
        int preSum = 0;
        storingPrefixSum[0]++;
        int totalSubarray = 0;
        for(int i=0; i<rowSum.size(); i++){
            preSum += rowSum[i];
            totalSubarray += storingPrefixSum[preSum-target];
            storingPrefixSum[preSum]++;
        }
        return totalSubarray;
    }
    
    int numSubmatrixSumTarget(vector<vector<int>>& matrix, int target) {
        int row = matrix.size();
        int col = matrix[0].size();
        int totalSubarraysOfSumK = 0;
        
        for(int i=0; i<row; i++){
            vector<int> rowSum(col,0);
            for(int j=i; j<row; j++){
                for(int k=0; k<col; k++){
                    rowSum[k] += matrix[j][k];
                }
                totalSubarraysOfSumK += findSubarray(rowSum,target);
            }
        }
        return totalSubarraysOfSumK;
    }
};
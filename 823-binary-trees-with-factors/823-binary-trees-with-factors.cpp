class Solution {
public:
    int numFactoredBinaryTrees(vector<int>& arr) {
        int noOfInt = arr.size();
        sort(arr.begin(), arr.end());
        unordered_map<int,long> dp;
        long m = pow(10,9)+7;
        long noOfBT = 0;
        for(int i=0; i<noOfInt; i++){
            dp[arr[i]] = 1;
            for(int j=0; j<i; j++){
                if(arr[i]%arr[j]==0){
                    int secondNum = arr[i]/arr[j];
                    if(dp.find(secondNum)!=dp.end()){
                        dp[arr[i]] = (dp[arr[i]] + dp[arr[j]]*dp[secondNum])% m;
                    }
                }
            }
            noOfBT  = (noOfBT + dp[arr[i]])%m;
        }
        return noOfBT;
    }
};
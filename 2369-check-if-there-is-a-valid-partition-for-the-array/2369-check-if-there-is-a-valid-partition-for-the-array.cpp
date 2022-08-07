class Solution {
public:
    
    
//     bool twoPart(int &i, int n, vector<int> &nums){
//         if(n-i<2){
//             return false;
//         }
//         int temp = i;
//         if(nums[temp]==nums[temp+1]){
//             temp += 2;
//             i = temp;
//             return true;
//         }
//         return false;
//     }
    
//     bool threeSame(int &i, int n, vector<int> &nums){
//         if(n-i<3){
//             return false;
//         }
//         int temp = i;
//         if(nums[temp]==nums[temp+1] && nums[temp+1]==nums[temp+2]){
//             temp += 3;
//             i = temp;
//             return true;
//         }
//         return false;
//     }
    
//      bool threePart(int &i, int n, vector<int> &nums){
//         if(n-i<3){
//             return false;
//         }
//         int temp = i;
//         if(nums[temp]+1==nums[temp+1] && nums[temp+1]+1==nums[temp+2]){
//             temp += 3;
//             i = temp;
//             return true;
//         }
//         return false;
//     }
    
    int dp[100001];
    int solve(int i,int n, vector<int> &nums){
        if(i==n){
            return 1;
        }
        if(dp[i]!=-1)
        {
            return dp[i];
        }
        int res = 0;
        if(i+1<n && nums[i]==nums[i+1]){
            res = res || solve(i+2,n,nums);
        }
        if(i+2<n && nums[i]==nums[i+1] && nums[i+1]==nums[i+2]){
            res = res || solve(i+3,n,nums);
        }
        if(i+2<n && nums[i]+1== nums[i+1] && nums[i+1]+1 == nums[i+2]){
            res = res || solve(i+3,n,nums);
        }
        dp[i] = res;
        return res;
    }
    
    bool validPartition(vector<int>& nums) {
        memset(dp,-1,sizeof(dp));
        int n = nums.size();
        int i=0;
        return solve(i,n,nums);
    }
    
};
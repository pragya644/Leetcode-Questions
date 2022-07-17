class Solution {
public:
    
    int minOperations(vector<int>& nums, vector<int>& numsDivide) {
        sort(nums.begin(),nums.end());
        int gcd = numsDivide[0];
        for(auto x: numsDivide)
            gcd = __gcd(gcd,x);
        int noOfDeletion = 0;
        for(int i=0; i<nums.size(); i++)
        {
            if(gcd%nums[i]==0)
            {
                return i;
            }
        }
        return -1;
    }
};
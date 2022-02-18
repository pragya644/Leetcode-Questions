class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
        vector<int> left;
        vector<int> right(n,1);
        int mul = 1;
        for(int i=0; i<n; i++)
        {
            mul = mul*nums[i];
            left.push_back(mul);
        }
        mul = 1;
        for(int i=n-1; i>=0; i--)
        {
            mul = mul*nums[i];
            right[i] = mul;
        }
        vector<int> ans;
        for(int i=0; i<n; i++)
        {
            int temp = 1;
            if(i-1>=0)
                temp = left[i-1];
            if(i+1<n)
                temp = temp*right[i+1];
            ans.push_back(temp);
        }
        return ans;
    }
};
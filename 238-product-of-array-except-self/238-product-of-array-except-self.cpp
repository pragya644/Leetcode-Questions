class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        vector<int> left;
        vector<int> right;
        int n = nums.size();
        int temp1 = 1;
        int temp2 = 1;
        for(int i=0; i<n; i++)
        {
            temp1 = temp1*nums[i];
            temp2 = temp2*nums[n-i-1];
            left.push_back(temp1);
            right.push_back(temp2);
        }
        reverse(right.begin(),right.end());
        vector<int> res;
        for(int i=0; i<n; i++)
        {
            int mul = 1;
            if(i-1>=0)
                mul = mul*left[i-1];
            if(i+1<n)
                mul = mul*right[i+1];
            res.push_back(mul);
        }
        return res;
    }
};
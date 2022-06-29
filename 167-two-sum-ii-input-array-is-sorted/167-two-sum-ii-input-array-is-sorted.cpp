class Solution {
public:
    vector<int> twoSum(vector<int>& num, int target) {
        int n = num.size();
        vector<int> ans;
        int l = 0, r = n-1;
        while(l<r)
        {
            int sum = num[l]+num[r];
            if(sum==target)
            {
                ans.push_back(l+1);
                ans.push_back(r+1);
                break;
            }
            else if(sum<target)
            {
                l++;
            }
            else
                r--;
        }
        return ans;
    }
};
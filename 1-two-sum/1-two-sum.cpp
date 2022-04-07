class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int , int> M;
        for(int i=0; i<nums.size(); i++)
        {
            M[nums[i]] = i;
        }
        vector<int> ans;
        for(int i = 0 ; i < nums.size(); i++)
        {
            int d;
            d = target - nums[i];
            if(M.find(d)!=M.end() && M[d]!=i)
            {
                ans.push_back(i);
                ans.push_back(M[d]);
                break;
            }
        }
        return ans;
    }
};
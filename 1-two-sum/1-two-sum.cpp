class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int,int> m;
        int n = nums.size();
        vector<int> res;
        for(int i=0; i<n; i++)
            m[nums[i]] = i;
        for(int i=0; i<n; i++)
        {
            int diff = target-nums[i];
            if(m.find(diff)!=m.end() && m[diff]!=i)
            {
                res.push_back(i);
                res.push_back(m[diff]);
                break;
            }
        }
        return res;
    }
};
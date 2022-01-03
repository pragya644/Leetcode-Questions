class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int,int> m;
        vector<int> res;
        for(int i=0; i<nums.size(); i++)
        {
            m[nums[i]] = i;
        }
        for(int i=0; i<nums.size(); i++)
        {
            int diff = target-nums[i];
            if(m.find(diff)!=m.end())
            {
                auto it = m.find(diff);
                if(it->second!=i)
                {
                    res.push_back(i);
                    res.push_back(it->second);
                    break;
                }
            }
        }
        return res;
    }
};
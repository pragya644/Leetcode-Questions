class Solution {
public:
    int fourSumCount(vector<int>& nums1, vector<int>& nums2, vector<int>& nums3, vector<int>& nums4)
    {
        unordered_map<int,int> m;
        int res = 0;
        for(auto x: nums1)
        {
            for(auto y: nums2)
            {
                int sum = x+y;
                m[sum]++;
            }
        }
        for(auto x: nums3)
        {
            for(auto y: nums4)
            {
                auto diff = m.find(0-(x+y));
                if(m.find(0-(x+y))!=m.end())
                    res += diff->second;
            }
        }
        return res;
    }
};
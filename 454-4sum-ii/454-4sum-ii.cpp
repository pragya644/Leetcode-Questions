class Solution {
public:
    int fourSumCount(vector<int>& nums1, vector<int>& nums2, vector<int>& nums3, vector<int>& nums4) 
    {
        unordered_map<int,int> m;
        int count = 0;
        for(auto a: nums1)
            for(auto b: nums2)
                m[a+b]++;
        for(auto c: nums3)
            for(auto d: nums4)
            {
                auto it = m.find(0-c-d);  
                if(m.find(0-c-d)!=m.end())
                    count += it->second;
            }
        return count;
    }
};
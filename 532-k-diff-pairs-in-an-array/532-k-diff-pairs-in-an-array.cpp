class Solution {
public:
    int findPairs(vector<int>& nums, int k) {
        unordered_map<int, int> m;
        int n = nums.size();
        for(int i=0; i<n; i++)
            m[nums[i]]++;
        int count = 0;
        if(k!=0)
        {
            for(auto x: m)
            {
                if(m.find(x.first+k)!=m.end())
                    count++;
            }
        }
        else
        {
            for(auto x: m)
                if(x.second>1)
                    count++;
        }
        return count;
    }
};
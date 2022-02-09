class Solution {
public:
    int findPairs(vector<int>& nums, int k) {
        unordered_map<int, int> m;
        int n = nums.size();
        for(int i=0; i<n; i++)
            m[nums[i]]++;
        int count = 0;
        sort(nums.begin(), nums.end());
        for(int i=0; i<n; i++)
        {
            if(i>0 && nums[i]==nums[i-1])
                continue;
            int diff = nums[i]-k;
            if(m.find(diff)!=m.end())
            {
                if(diff==nums[i])
                {
                    if(m[diff]>1)
                        count++;
                }
                else
                    count++;
            }
        }
        return count;
    }
};
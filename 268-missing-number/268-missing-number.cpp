class Solution {
public:
    int missingNumber(vector<int>& nums) {
        unordered_set<int> m;
        int n = nums.size();
        for(int i=0; i<n; i++)
            m.insert(nums[i]);
        for(int i=0; i<=n; i++)
        {
            if(m.find(i)==m.end())
                return i;
        }
        return 0;
    }
};
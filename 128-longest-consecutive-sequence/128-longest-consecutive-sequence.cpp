class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        int ans = 0;
        unordered_set<int> s;
        int n = nums.size();
        for(int i=0; i<n; i++)
            s.insert(nums[i]);
        for(int i=0; i<n; i++)
        {
            if(s.find(nums[i]-1)==s.end())
            {
                int temp = nums[i]+1;
                int count = 1;
                while(s.find(temp)!=s.end())
                {
                    temp++;
                    count++;
                }
                ans = max(ans, count);
            }
        }
        return ans;
    }
};
class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        int n = nums.size();
        unordered_set<int> s;
        for(int i=0; i<nums.size(); i++)
        {
            s.insert(nums[i]);
        }
        int ans = 0;
        for(int i=0; i<n; i++)
        {
            if(s.find(nums[i]-1)==s.end())
            {
                int temp = nums[i]+1;
                int count = 1;
                while(s.find(temp)!=s.end())
                {
                    count++;
                    temp++;
                }
                ans = max(count,ans);
            }
        }
        return ans;
    }
};
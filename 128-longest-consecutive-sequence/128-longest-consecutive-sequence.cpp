class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> s;
        int n = nums.size();
        int res = 0;
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
                res = max(res,count);
            }
        }
        return res;
    }
};
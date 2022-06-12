class Solution {
public:
    int maximumUniqueSubarray(vector<int>& nums) {
        int n = nums.size();
        int result = 0;
        unordered_set<int> s;
        int i=0;
        int temp = 0;
        for(int j=0; j<n; j++)
        {
            while(s.find(nums[j])!=s.end())
            {
                s.erase(nums[i]);
                temp -= nums[i];
                i++;
            }
            temp += nums[j];
            s.insert(nums[j]);
            result = max(result, temp);
        }
        return result;
    }
};
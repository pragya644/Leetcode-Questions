class Solution {
public:
    vector<string> summaryRanges(vector<int>& nums) {
        vector<string> ans;
        string temp;
        int n = nums.size();
        for(int i=0; i<n; i++)
        {
            int j = i;
            while(j+1<n && nums[j]==nums[j+1]-1)
            {
               j++;
            }
            if(j>i)
            {
                temp += to_string(nums[i]);
                temp += "->";
                temp += to_string(nums[j]);
            }
            else
            {
                temp += to_string(nums[i]);
            }
            ans.push_back(temp);
            temp = "";
            i = j;
        }
        return ans;
    }
};
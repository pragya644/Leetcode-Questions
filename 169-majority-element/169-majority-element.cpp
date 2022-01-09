class Solution {
public:
    int majorityElement(vector<int>& nums) {
        unordered_map<int,int> m;
        int n = nums.size();
        for(int i=0; i<nums.size(); i++)
            m[nums[i]]++;
        int x = n/2;
        for(int i=0; i<nums.size(); i++)
        {
            if(m[nums[i]]>x)
                return nums[i];
        }
        return 0;
    }
};
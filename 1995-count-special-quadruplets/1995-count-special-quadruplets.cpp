class Solution {
public:
    int countQuadruplets(vector<int>& nums) {
        int n = nums.size();
        int count = 0;
        unordered_map<int,int> m;
        for(int i=n-1; i>1; i--)
        {
            for(int j=i-1; j>0; j--)
            {
                for(int k=j-1; k>=0; k--)
                {
                    if(m.count(nums[i]+nums[j]+nums[k]))
                    {
                        count += m[nums[i]+nums[j]+nums[k]];
                    }
                }
            }
            m[nums[i]]++;
        }
        return count;
    }
};
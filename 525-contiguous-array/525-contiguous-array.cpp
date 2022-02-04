class Solution {
public:
    int findMaxLength(vector<int>& nums) {
        int presum = 0;
        int n = nums.size();
        unordered_map<int,int> m;
        int res = 0;
        for(int i=0; i<n; i++)
        {
            if(nums[i]==0)
                nums[i]= -1;
        }
        
        for(int i=0; i<n; i++)
        {
            presum += nums[i];
            if(presum==0)
                res = i+1;
            if(m.find(presum)==m.end())
                m[presum] = i;
            else
                res = max(res, i-m[presum]);
        }
        return res;
    }
};
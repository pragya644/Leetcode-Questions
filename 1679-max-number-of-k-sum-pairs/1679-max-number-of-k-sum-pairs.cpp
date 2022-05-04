class Solution {
public:
    int maxOperations(vector<int>& nums, int k) {
        int n = nums.size();
        if(n==0)
            return 0;
        unordered_map<int,int> m;
        for(int i=0; i<n; i++)
            m[nums[i]]++;
        int ans = 0;
        for(int i=0; i<n; i++)
        {
            int diff = k-nums[i];
            if(diff == nums[i])
            {
                if(m.find(diff)!=m.end() && m[diff]>1){
                    m[diff] = m[diff]-2;
                    ans++;
                }
            }
            else
            {
                if(m.find(diff)!=m.end() && m[diff]>0 && m[nums[i]]>0)
                {
                    m[diff]--;
                    m[nums[i]]--;
                    ans++;
                }
            }
        }
        return ans;
    }
};
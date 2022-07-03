class Solution {
public:
    int wiggleMaxLength(vector<int>& nums) {
        if(nums.size()==1)
            return 1;
        vector<int> diffBtwSucc;
        for(int i=1; i<nums.size(); i++)
        {
            int diff = nums[i]-nums[i-1];
            diffBtwSucc.push_back(diff);
        }
        int n = diffBtwSucc.size();
        vector<int> maxLen(n,1);
        int ans = 0;
        for(int i=1; i<n; i++)
        {
            if(diffBtwSucc[i]==0)
                continue;
            for(int j=0; j<i; j++)
            {
                if(diffBtwSucc[i]>0 && diffBtwSucc[j]<0)
                {
                    maxLen[i] = max(maxLen[i], maxLen[j]+1);
                }
                else if(diffBtwSucc[i]<0 && diffBtwSucc[j]>0)
                {
                    maxLen[i] = max(maxLen[i], maxLen[j]+1);
                }
            }
            ans = max(ans, maxLen[i]);
        }
        return ans+1;
    }
};
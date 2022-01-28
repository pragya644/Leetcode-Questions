class Solution {
public:
    vector<int> findDisappearedNumbers(vector<int>& nums) {
        int n = nums.size();
        vector<int> vis(n+1,0);
        for(int i=0; i<n; i++)
        {
            vis[nums[i]]++;
        }
        vector<int> res;
        for(int i=1; i<n+1; i++)
            if(vis[i]==0)
                res.push_back(i);
        return res;
    }
};
class Solution {
public:
    bool isairthmetic(vector<int> v)
    {
        int n = v.size();
        sort(v.begin(),v.end());
        int diff = v[1]-v[0];
        for(int i=1; i<n-1; i++)
        {
            if(v[i+1]-v[i]!=diff)
                return false;
        }
        return true;
    }
    
    vector<bool> checkArithmeticSubarrays(vector<int>& nums, vector<int>& l, vector<int>& r) 
    {
        int n = nums.size();
        int m = l.size();
        vector<bool> res;
        for(int i=0; i<m; i++)
        {
            int x = l[i];
            int y = r[i];
            vector<int> temp;
            for(int j=x; j<=y; j++){
                temp.push_back(nums[j]);
            }
            if(isairthmetic(temp))
                res.push_back(true);
            else
                res.push_back(false);
        }
        return res;
    }
};
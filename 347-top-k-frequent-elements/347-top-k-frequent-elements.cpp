class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        vector<pair<int,int>> v;
        vector<int> res;
        int n = nums.size();
        int i = 1;
        int count = 1;
        while(i<n)
        {
            if(nums[i]==nums[i-1])
            {
                count++;
                i++;
            }
            else{
                v.push_back(make_pair(count,nums[i-1]));
                count = 1;
                i++;
            }
        }
        v.push_back(make_pair(count,nums[i-1]));
        sort(v.rbegin(), v.rend());
        for(i=0; i<k; i++)
        {
            res.push_back(v[i].second);
        }
        return res;
    }
};
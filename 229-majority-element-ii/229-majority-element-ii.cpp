class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        vector<int> res;
        int n = nums.size();
        int x = n/3;
        unordered_map<int,int> m;
        for(int i=0; i<n; i++)
            m[nums[i]]++;
        for(auto a: m)
            if(a.second> x)
                res.push_back(a.first);
        return res;
    }
};
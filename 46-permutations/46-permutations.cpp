class Solution {
public:
    void perm(vector<vector<int>> &ans, vector<int> &temp, int check[], vector<int> &nums)
    {
        if(temp.size()==nums.size())
            ans.push_back(temp);
        for(int i=0; i<nums.size(); i++)
        {
            if(check[i]==0)
            {
                temp.push_back(nums[i]);
                check[i] = 1;
                perm(ans,temp,check,nums);
                temp.pop_back();
                check[i] = 0;
            }
        }
    }
    
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> temp;
        int check[nums.size()];
        for(int i=0; i<nums.size(); i++)
            check[i] = 0;
        perm(ans,temp, check, nums);
        return ans;
    }
};
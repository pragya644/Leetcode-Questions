class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
        // int m = nums.size();
        // time complexity = O(m)+O(n);
        // space complexity = O(m);
        vector<int> pos;
        vector<int> neg;
        for(int i=0; i<nums.size(); i++)
        {
            if(nums[i]>0)
                pos.push_back(nums[i]);
            else
                neg.push_back(nums[i]);
        }
        int n = pos.size();
        int idx = 0;
        for(int i=0; i<n; i++)
        {
            if(idx%2==0)
                nums[idx] = pos[i];
            idx++;
            if(idx%2!=0)
                nums[idx] = neg[i];
            idx++;
        }
        return nums;
    }
};
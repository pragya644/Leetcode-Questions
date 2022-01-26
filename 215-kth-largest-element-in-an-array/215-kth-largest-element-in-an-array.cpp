class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        priority_queue<int> pq;
        int n = nums.size()-k+1;
        for(int i=0; i<nums.size(); i++)
        {
            if(pq.size()<n)
                pq.push(nums[i]);
            else
            {
                if(pq.top()>nums[i])
                {
                    pq.pop();
                    pq.push(nums[i]);
                }
            }
        }
        return pq.top();
    }
};
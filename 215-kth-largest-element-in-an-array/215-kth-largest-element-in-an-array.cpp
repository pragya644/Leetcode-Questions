class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        priority_queue<int> pq;
        int n = nums.size();
        for(int i=0; i<n; i++)
            pq.push(nums[i]);
        for(int i=1; i<k; i++)
            pq.pop();
        return pq.top();
    }
};
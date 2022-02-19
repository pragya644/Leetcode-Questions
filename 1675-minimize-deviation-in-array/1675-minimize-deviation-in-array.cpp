class Solution {
public:
    int minimumDeviation(vector<int>& nums) {
        int n = nums.size();
        for(int i=0; i<n; i++)
            if(nums[i]%2!=0)
                nums[i] = nums[i]*2;
        priority_queue<int> pq;
        int mini = INT_MAX;
        for(int i=0; i<n; i++)
        {
            if(nums[i]<mini)
                mini = nums[i];
            pq.push(nums[i]);
        }
        
        int diff = INT_MAX;
        while((pq.top())%2==0)
        {
            int x = pq.top();
            pq.pop();
            int temp = x-mini;
            diff = min(temp,diff);
            x = x/2;
            mini = min(x,mini);
            pq.push(x);
        }
        diff = min(diff,pq.top()-mini);
        return diff;
    }
};
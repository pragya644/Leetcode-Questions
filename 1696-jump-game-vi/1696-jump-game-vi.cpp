class Solution {
public:
    
    // time complexity of multiset is O(nlogK), because n for traversal and find function in mutliset take O(logk) where k is the size of the multiset
    
    //time complexity of monostanic queue or dequeu is O(n)
    
    int maxResult(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> dp(n);
        deque<int> q;
        dp[0] = nums[0];
        q.push_back(0);
        for(int i=1; i<n; i++)
        {
            if(i-q.front()>k)
                q.pop_front();
            dp[i] = nums[i] + dp[q.front()];
            while(q.size()>0 && dp[q.back()]<dp[i])
                q.pop_back();
            q.push_back(i);
        }
        return dp[n-1];
    }
};
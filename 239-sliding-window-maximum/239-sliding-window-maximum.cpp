class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        int n = nums.size();
        deque<int> dq;
        vector<int> ans;
        for(int i=0; i<k; i++){
            while(dq.empty()==false && nums[dq.back()]<nums[i]){
                dq.pop_back();
            }
            dq.push_back(i);
        }
        ans.push_back(nums[dq.front()]);
        for(int i=k; i<n; i++){
            int range = i-k+1;
            while(dq.empty()==false && dq.front()<range){
                dq.pop_front();
            }
            while(dq.empty()==false && nums[dq.back()]<nums[i]){
                dq.pop_back();
            }
            dq.push_back(i);
            ans.push_back(nums[dq.front()]);
        }
        return ans;
        
    }
    
};
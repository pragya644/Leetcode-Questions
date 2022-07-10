class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        int n = nums.size();
        unordered_map<int,int> countOfSameElement;
        vector<int> ans;
        for(int i=0; i<n; i++)
        {
            countOfSameElement[nums[i]]++;
        }
        priority_queue<pair<int,int>> pq;
        for(auto x: countOfSameElement)
        {
            pq.push({x.second,x.first});
        }
        while(k>0)
        {
            auto curr = pq.top();
            pq.pop();
            ans.push_back(curr.second);
            k--;
        }
        return ans;
    }
};
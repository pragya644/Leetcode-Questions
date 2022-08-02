class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        map<int,int> storingFreq;
        for(auto x: nums){
            storingFreq[x]++;
        }
        priority_queue<pair<int,int>> maxFreq;
        for(auto x: storingFreq){
            maxFreq.push({x.second,x.first});
        }
        vector<int> ans;
        while(k>0){
            auto curr = maxFreq.top();
            maxFreq.pop();
            ans.push_back(curr.second);
            k--;
        }
        return ans;
    }
};
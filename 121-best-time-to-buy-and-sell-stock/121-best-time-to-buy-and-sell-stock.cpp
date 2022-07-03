class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        int buy = INT_MAX;
        int ans = 0;
        for(int i=0; i<n; i++)
        {
            buy = min(buy,prices[i]);
            int diff = prices[i]-buy;
            ans = max(ans, diff);
        }
        return ans;
    }
};
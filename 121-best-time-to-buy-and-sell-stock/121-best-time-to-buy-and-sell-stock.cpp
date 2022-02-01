class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int sell = INT_MAX;
        int profit = 0;
        int n = prices.size();
        for(int i=0; i<n; i++)
        {
            sell = min(sell,prices[i]);
            int diff = prices[i]-sell;
            profit = max(profit,diff);
        }
        return profit;
    }
};
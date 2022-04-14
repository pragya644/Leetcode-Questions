class Solution {
public:
    int maxProfit(vector<int>& prices, int fee) {
        int n = prices.size();
        vector<int> buy(n,0);
        vector<int> sell(n,0);
        buy[0] = -prices[0];
        int res = 0;
        for(int i=1; i<n; i++)
        {
            sell[i] = max(sell[i-1], buy[i-1]+prices[i]-fee);
            res = max(res,sell[i]);
            buy[i] = max(buy[i-1], sell[i-1]-prices[i]);
        }
        return res;
    }
};
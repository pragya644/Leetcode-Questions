class Solution {
public:
    int maxCoins(vector<int>& piles) {
        int ans = 0;
        int n = piles.size();
        int pair = n/3;
        sort(piles.begin(), piles.end());
        for(int i=n-2; i>=pair; i = i-2)
        {
           ans += piles[i];
        }
        return ans;
    }
};
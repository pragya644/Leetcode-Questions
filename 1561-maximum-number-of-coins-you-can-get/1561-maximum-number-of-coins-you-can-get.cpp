class Solution {
public:
    int maxCoins(vector<int>& piles) {
        int a[10001] = {0};
        int n = piles.size();
        for(int i=0; i<n; i++)
        {
            a[piles[i]]++;
        }
        int ans = 0;
        int count = n/3;
        int last = 10000;
        while(count--)
        {
            while(last>0 && a[last]==0)
                last--;
            a[last]--;
            while(last>0 && a[last]==0)
                last--;
            ans += last;
            a[last]--;
        }
        return ans;
    }
};
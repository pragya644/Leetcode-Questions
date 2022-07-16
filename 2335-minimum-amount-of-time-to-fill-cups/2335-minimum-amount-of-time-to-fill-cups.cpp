class Solution {
public:
    int fillCups(vector<int>& amount) {
        sort(amount.begin(), amount.end());
        int ans = 0;
        while(amount[2]!=0)
        {
            ans++;
            amount[2]--;
            if(amount[1]>0)
                amount[1]--;
            sort(amount.begin(), amount.end());
        }
        return ans;
    }
};
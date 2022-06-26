class Solution {
public:
    int countHousePlacements(int n) {
        int mod = 1e9 + 7;
        int house = 1;
        int space = 1;
        int total = house + space;
        for(int i=2; i<=n; i++)
        {
            house = space;
            space = total;
            total = (house+space)%mod;
        }
        return ((long long)total*total)%mod;
    }
};
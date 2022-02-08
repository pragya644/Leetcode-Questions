class Solution {
public:
    int addDigits(int num) {
        int ans = 1+(num-1)%9;
        return ans;
    }
};
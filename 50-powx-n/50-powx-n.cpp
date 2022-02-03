class Solution {
public:
    double myPow(double x, int n) {
        if(n==0)
            return 1;
        double ans = myPow(x,n/2);
        if(n%2==0)
            return ans*ans;
        else
            return n>=0 ? x*ans*ans : 1/x*ans*ans;
    }
};
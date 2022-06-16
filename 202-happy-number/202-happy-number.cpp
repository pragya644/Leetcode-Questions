class Solution {
public:
    int solve(int n)
    {
        int temp;
        int sum = 0;
        while(n>0)
        {
            temp = n%10;
            n = n/10;
            sum += temp*temp;
        }
        return sum;
    }
    
    bool isHappy(int n) {
        int slow = n;
        int fast = solve(n);
        while(true)
        {
            if(fast==1)
                return true;
            if(slow==fast)
                return false;
            slow = solve(slow);
            fast = solve(solve(fast));
        }
        return true;
    }
};
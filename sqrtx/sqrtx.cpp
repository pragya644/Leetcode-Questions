class Solution {
public:
    int mySqrt(int x) {
        long long low = 1; 
        long long high = x;
        long long ans = 0;
        while(low<=high)
        {
            long long  mid = (low + high)/2;
            long long sq = mid*mid;
            if(sq==x)
            {
                return mid;
            }
            else if(sq>x)
                high = mid-1;
            else{
                low = mid+1;
                ans = mid;
            }
        }
        return ans;
    }
};
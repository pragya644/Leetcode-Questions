class Solution {
public:
    // void power(int n, int count)
    // {
    //     if(n==1)
    //         return;
    //     if(n%2==0)
    //     {
    //         count++;
    //         power(n/2,count);
    //     }
    //     else
    //     {
    //         count++;
    //         power(3*n+1, count);
    //     }
    // }
    
    int power(int n)
    {
        int count = 0;
        while(n!=1)
        {
            if(n%2==0)
                n = n/2;
            else
                n = 3*n+1;
            count++;
        }
        return count;
    }
    
//     bool sortacc(const pair<int,int> &a, const pair<int,int> &b)
//     {
//         if(a.first!=b.first)
//            return (a.first < b.first);
//         return (a.second<b.second);
//     }
    
    int getKth(int lo, int hi, int k) {
        int temp = lo;
        int n = hi-lo+1;
        vector<pair<int,int>> v;
        for(int i=0; i<n; i++)
        {
            // int count = 0;
            // power(temp, count);
            // v.push_back({count,temp});
            // temp++;
            v.push_back({power(temp), temp});
            temp++;
        }
        sort(v.begin(), v.end());
        return v[k-1].second;
    }
};
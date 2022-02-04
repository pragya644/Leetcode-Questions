// { Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
/*You are required to complete this function*/

class Solution{
    public:
    int maxLen(vector<int>&num, int n)
    {   
        int res = 0;
        int presum = 0;
        unordered_map<int,int> m;
        for(int i=0; i<n; i++)
        {
            presum += num[i];
            if(presum == 0)
            {
                res = i+1;
            }
            if(m.find(presum)==m.end())
               m[presum] = i;
            else
            {
                res = max(res, i-m[presum]);
            }
        }
        return res;
    }
};


// { Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int m;
        cin>>m;
        vector<int> array1(m);
        for (int i = 0; i < m; ++i){
            cin>>array1[i];
        }
        Solution ob;
        cout<<ob.maxLen(array1,m)<<endl;
    }
    return 0; 
}


  // } Driver Code Ends
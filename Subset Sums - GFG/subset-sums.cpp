// { Driver Code Starts
#include<bits/stdc++.h> 
using namespace std; 

 // } Driver Code Ends
class Solution
{
public:
    void recursive(vector<int> arr, int sum, int n,int i, vector<int> &res)
    {
        if(i==n)
        {
            res.push_back(sum);
            return;
        }
        recursive(arr, sum+arr[i], n, i+1, res);
        recursive(arr, sum, n, i+1, res);
    }

    
    vector<int> subsetSums(vector<int> arr, int N)
    {
        vector<int> res;
        recursive(arr,0,N,0,res);
        sort(res.begin(),res.end());
        return res;
    }
};

// { Driver Code Starts.
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int N;
        cin>>N;
        vector<int> arr(N);
        for(int i = 0 ; i < N ; i++){
            cin >> arr[i];
        }
        Solution ob;
        vector<int> ans = ob.subsetSums(arr,N);
        sort(ans.begin(),ans.end());
        for(auto sum : ans){
            cout<< sum<<" ";
        }
        cout<<endl;
    }
    return 0;
}  // } Driver Code Ends
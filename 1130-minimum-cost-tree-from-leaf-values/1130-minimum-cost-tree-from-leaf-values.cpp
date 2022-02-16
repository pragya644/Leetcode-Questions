class Solution {
public:
    int mctFromLeafValues(vector<int>& arr) {
        int ans = 0;
        while(arr.size()>1)
        {
            int minvalue = INT_MAX;
            int idx = 0;
            for(int i=0; i<arr.size()-1; i++)
            {
                int prod = arr[i]*arr[i+1];
                if(prod<minvalue)
                {
                    minvalue = prod;
                    idx = i;
                }
            }
            ans += minvalue;
            if(arr[idx+1]<arr[idx])
                idx++;
            arr.erase(arr.begin()+idx);
        }
        return ans;
    }
};
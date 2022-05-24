class Solution {
public:
    int hammingDistance(int x, int y) {
        vector<int> v1;
        while(x>0)
        {
            v1.push_back(x%2);
            x= x/2;
        }
        vector<int> v2;
        while(y>0)
        {
            v2.push_back(y%2);
            y = y/2;
        }
        int ans = 0;
        int n = v1.size();
        int m = v2.size();
        int i=0,j=0;
        while(i<n && j<m)
        {
            if(v1[i]!=v2[j])
                ans++;
            i++;
            j++;
        }
        while(j<m)
        {
            if(v2[j]==1)
                ans++;
            j++;
        }
        while(i<n)
        {
            if(v1[i]==1)
                ans++;
            i++;
        }
        return ans;
    }
};
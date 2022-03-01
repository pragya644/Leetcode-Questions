class Solution {
public:
    int bitscount(int n)
    {
        int temp = n;
        int count = 0;
        while(temp>0)
        {
            if(temp%2==1)
                count++;
            temp = temp/2;
        }
        return count;
    }
    
    vector<int> countBits(int n) {
        vector<int> ans;
        for(int i=0; i<=n; i++)
        {
            ans.push_back(bitscount(i));
        }
        return ans;
    }
};
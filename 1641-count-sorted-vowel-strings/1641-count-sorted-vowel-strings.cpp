class Solution {
public:
    int countVowelStrings(int n) {
        vector<int> v(5,1);
        if(n>1){
        for(int i=1; i<n; i++)
        {
            for(int j=3; j>=0; j--)
                v[j] = v[j]+v[j+1];
        }
        }
        int res = 0;
        for(auto x: v)
            res += x;
        return res;
    }
};
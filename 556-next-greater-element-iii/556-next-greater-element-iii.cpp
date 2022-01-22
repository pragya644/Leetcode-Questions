class Solution {
public:
    int nextGreaterElement(int n) {
        string s = to_string(n);
        int i = s.length()-2;
        while(i>=0)
        {
            if(s[i]<s[i+1])
            {
                break;
            }
            i--;
        }
        if(i==-1)
            return -1;
        reverse(s.begin()+i+1, s.end());
        for(int j=i+1; j<s.length(); j++)
        {
            if(s[j]>s[i])
            {
                swap(s[j],s[i]);
                break;
            }
        }
        long ans = stol(s);
        return ans==n || ans > INT_MAX?-1:ans;
    }
};
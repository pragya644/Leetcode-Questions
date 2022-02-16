class Solution {
public:
    bool checkIfCanBreak(string s1, string s2) {
        int count1 = 0;
        int count2 = 0;
        int neutral = 0;
        sort(s1.begin(), s1.end());
        sort(s2.begin(), s2.end());
        int n1 = s1.length();
        int n2 = s2.length();
        if(n1!=n2)
            return false;
        for(int i=0; i<n1; i++)
        {
            if(s1[i]>s2[i])
                count1++;
            else if(s2[i]>s1[i])
                count2++;
            else
                neutral++;
        }
        if(count1==(n1-neutral) || count2==(n1-neutral))
            return true;
        return false;
    }
};
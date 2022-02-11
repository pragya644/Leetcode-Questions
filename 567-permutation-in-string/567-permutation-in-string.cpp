class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        int l1 = s1.length();
        int l2 = s2.length();
        if(l2<l1)
            return false;
        unordered_map<char,int> m1;
        for(int i=0; i<l1; i++)
        {
            m1[s1[i]]++;
        }
        unordered_map<char, int> m2;
        for(int i=0; i<l1; i++)
            m2[s2[i]]++;
        
        if(m1==m2)
            return true;
        for(int i=0; i<l2-l1; i++)
        {
            if(m1==m2)
                return true;
            if(m2[s2[i]]==1)
                m2.erase(s2[i]);
            else
                m2[s2[i]]--;
            m2[s2[l1+i]]++;
        }
        if(m1==m2)
            return true;
        return false;
    }
};
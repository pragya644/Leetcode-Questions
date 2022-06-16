class Solution {
public:
    bool isHappy(int n) {
        unordered_set<int> s;
        int temp = n;
        int curr = 0;
        s.insert(n);
        while(true)
        {
            while(n>0)
            {
               temp = n%10;
               n = n/10;
               curr += temp*temp;
            }
            if(curr == 1)
                return true;
            if(s.find(curr)!=s.end())
                return false;
            s.insert(curr);
            n = curr;
            curr = 0;
        }
        return true;
    }
};
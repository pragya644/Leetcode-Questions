class Solution {
public:
    int minPartitions(string n) {
        char temp = '0';
        for(auto x: n)
        {
            temp = max(x,temp);
        }
        return temp-'0';
    }
};
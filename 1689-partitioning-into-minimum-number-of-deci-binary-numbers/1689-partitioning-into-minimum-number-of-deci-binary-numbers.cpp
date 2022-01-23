class Solution {
public:
    int minPartitions(string n) {
        sort(n.begin(), n.end());
        int y = n.length();
        char temp = n[y-1];
        int ans = (int)temp;
        return ans-48;
    }
};
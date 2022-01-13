class Solution {
public:
    uint32_t reverseBits(uint32_t n) {
        bitset<32> b(n);
        int l{0}, r{31};
        while(l<r)
        {
            bool temp = b[l];
            b[l] = b[r];
            b[r] = temp;
            l++;
            r--;
        }
        return b.to_ulong();
    }
};
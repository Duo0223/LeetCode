class Solution {
public:
    uint32_t reverseBits(uint32_t n) {
        unsigned ret = 0;
        unsigned pos1 = 1 << 31;
        unsigned pos2 = 1;
        while(pos1)
        {
            if(pos1 & n)
                ret |= pos2;
            pos2 <<= 1;
            pos1 >>= 1;
        }
        return ret;
    }
};

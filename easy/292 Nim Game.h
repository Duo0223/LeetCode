class Solution {
public:
    bool canWinNim(int n) {
        static const int mask = 0x00000003;
		return (n & mask) != 0;
    }
};
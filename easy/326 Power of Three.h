class Solution {
public:
    bool isPowerOfThree(int n)
    {
        double ret = log10(n)/log10(3);
        if( ( ret - (int)ret ) == 0 )
            return true;
        return false;
    }
};
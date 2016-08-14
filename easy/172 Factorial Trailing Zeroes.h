class Solution {
public:
    int trailingZeroes(int n)
    {
        int count = 0;
        double dn = (double)n;
        double factor = 1.0;
        int ret = 0;
        do
        {
            factor *= 5.0;
            ret = (int) (dn/factor);
            count += ret;
        }while( ret > 0 );
        
        return count;
    }
};
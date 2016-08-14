class Solution {
public:
    int reverse(int x)
    {
        long long int result = 0;
        while(x)
        {
            int m= x % 10;
            result = result * 10 + m;
            x = x / 10;
        }
        int ret = (result >= INT_MIN && result <= INT_MAX) ? result : 0;
        return ret;
    }
};
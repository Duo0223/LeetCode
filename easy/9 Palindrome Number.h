class Solution {
public:
    bool isPalindrome(int x)
    {
        if( x < 0  ) return false;
        if( x < 10 ) return true;
        
        unsigned long rx = 0;
        int tmp  = x;
        while( tmp != 0 )
        {
            rx *= 10;
            rx += tmp%10;
            tmp /= 10;
        }
        return (rx == x);
    }
};
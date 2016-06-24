class Solution {
public:
    int titleToNumber(string s)
    {
        int baseA = ('A' - 1);
        int value = s[ 0 ] - baseA;
        for( int i = 1 ; i < s.length() ; ++i )
        {
            int tmp = ( s[i] - baseA );
            value = value * 26 + tmp;
        }
        return value;
    }
};
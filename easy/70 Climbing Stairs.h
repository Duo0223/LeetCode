class Solution {
public:
    int climbStairs(int n)
    {
        static const int maxSize = 1000;
        static int valueTable[ maxSize ] = {-1};
        valueTable[0] = 0;
        valueTable[1] = 1;
        valueTable[2] = 2;
        valueTable[3] = 3;
        
        if( n >= maxSize )
            return -1;
        
        static int nowIndex = 3;
        if( n > nowIndex )
        {
            for( int i = nowIndex + 1 ; i <= n ; ++i )
            {
                valueTable[ i ] += (valueTable[ i-1 ] + valueTable[ i-2 ]);
            }
            nowIndex = n;
        }
        return valueTable[ n ];

    }
};
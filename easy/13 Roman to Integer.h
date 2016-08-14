class Solution {
public:
    int romanToInt(string s)
    {
        int valueTable[ 26 ] = { 0 };
        valueTable[ 'I' - 'A' ] = 1;    // I
        valueTable[ 'V' - 'A' ] = 5;    // V
        valueTable[ 'X' - 'A' ] = 10;   // X
        valueTable[ 'L' - 'A' ] = 50;   // L
        valueTable[ 'C' - 'A' ] = 100;  // C
        valueTable[ 'D' - 'A' ] = 500;  // D
        valueTable[ 'M' - 'A' ] = 1000; // M
        
        int ret = 0;
        int length = s.length();
        int preValue = 1000000;
        for( int i = 0 ; i < length ; ++i )
        {
            int nowValue = valueTable[ s[i] - 'A' ];
            ret += valueTable[ s[i] - 'A' ];
            
            if( preValue < nowValue )
                ret -= preValue << 1;
            
            preValue = nowValue;
                
        }
        return ret;
    }
};
class Solution {
public:
    int myAtoi(string str)
    {
        bool negative = false;
        unsigned long long ret = 0;
        int strIndex = 0;
        
        while( str[strIndex] ==' ')
            ++strIndex;
    
        if(!isdigit( str[strIndex] ) && str[strIndex] != '+' && str[strIndex] != '-')
            return 0;
        
        if( str[strIndex] == '+' || str[strIndex] == '-')
        {
            if( !isdigit( str[strIndex + 1] ) )
                return 0;
            if( str[strIndex] == '-' )
                negative = true;
            ++strIndex;
        }
        
        while( isdigit( str[strIndex] ) )
        {
            ret = ret * 10 + ( str[strIndex] - '0' );
            if( ret > INT_MAX )
                return negative ? INT_MIN : INT_MAX;
            ++strIndex;
        }
        return negative ? -(int)ret : (int)ret;
    }
};
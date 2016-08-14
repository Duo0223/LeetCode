class Solution {
public:
    vector<int> plusOne(vector<int>& digits)
    {
        const int digitSize = digits.size();
        const int reserveSize = ( digits[0] == 9 ? digitSize + 1 : digitSize );
        int carry = 0;
        
        vector< int > ret;
        ret.resize( reserveSize );
        
        ++digits[ digitSize - 1 ];
        carry = digits[ digitSize - 1 ] / 10;
        digits[ digitSize - 1 ] = digits[ digitSize - 1 ] % 10;
        
        int i  = -1;
        for( int i = digitSize - 2 ; i >= 0 && carry == 1 ; --i )
        {
            digits[ i ] += carry;
            carry = digits[ i ] / 10;
            digits[ i ] = digits[ i ] % 10;
        }
        
        if( carry == 1 && i < 0 )
        {
            std::copy( digits.begin() , digits.end() , ret.begin() + 1 );
            ret[0] = 1;
            return ret;
        }
        return digits;
    }
};
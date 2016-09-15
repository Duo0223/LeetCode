class Solution
{
protected:
    void revertString( string &_str )
    {
        int i = 0;
        int j = (int)_str.length() - 1;
        while( i < j )
        {
            char tmp = _str[i];
            _str[i] = _str[j];
            _str[j] = tmp;
            ++i;
            --j;
        }
    }
public:
    string addBinary(string a, string b)
    {
        if( a == "0" && b == "0" )  return string("0");
        
        const int lenA = (int)a.length();
        const int lenB = (int)b.length();
        const int maxLen = max( lenA , lenB );
        revertString(a);
        revertString(b);
        
        char *charStr = new char[ maxLen + 1 ];
        memset( charStr , '0' , maxLen + 1 );
        char carry = '0';
        int count = 0;
        for( int i = 0 ; i < maxLen ; ++i )
        {
            count = 0;
            if( i < lenA && a[ i ] == '1' ) ++count;
            if( i < lenB && b[ i ] == '1' ) ++count;
            if( carry == '1' )              ++count;
            if( count & 0x01 )              charStr[ maxLen - i ] = '1';
            if( count > 1 )                 carry = '1';
            else                            carry = '0';
        }
        if( carry == '1' )      charStr[ 0 ] = '1';
        
        string retStr( charStr );
        
        delete [] charStr;
        int not_1_pos = (int)retStr.find_first_of('1');
        if( not_1_pos != string::npos )
            return retStr.substr( not_1_pos , maxLen + 1 - not_1_pos );
        
        return retStr;
    }
};
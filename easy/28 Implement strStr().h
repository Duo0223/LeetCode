class Solution
{
protected:
    void KMPpreprocessing( string &_str , vector<int> &_out )
    {
        int j = -1;
        for( int i = 1 ; i < _str.length() ; ++i)
        {
            while( j >= 0 && _str[i] != _str[ j+1 ] )
                j = _out[j];
            if( _str[i] == _str[j+1])
                ++j;
            _out[i] = j;
        }
    }
public:
    int strStr(string haystack, string needle)
    {
        int m = haystack.length();
        int n = needle.length();
        if( n == 0 ) return 0;
        if( m == 0 ) return -1;
    
        vector< int >  match( n , -1 );
        KMPpreprocessing( needle , match );
        int j = -1;
        for( int i = 0 ; i < m ; ++i)
        {
            while( j >= 0 && haystack[i] != needle[j+1] )
                j = match[j];
            if( haystack[i] == needle[j+1] )
                ++j;
            if( j == n-1)
                return ( i-n+1 );
        }
        return -1;
    }
};
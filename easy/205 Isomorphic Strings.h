class Solution {
public:
    bool isIsomorphic(string s, string t) 
    {
        char sTable[ 256 ];
        char tTable[ 256 ];
        memset( sTable , 0 , 256 );
        memset( tTable , 0 , 256 );
        
        for( int i = 0 ; i < s.length() ; ++i )
        {
            const int sIndex = (int)s[i];
            const int tIndex = (int)t[i];
            
            if( !sTable[sIndex] && !tTable[tIndex] )
            {
                sTable[sIndex] = t[i];
                tTable[tIndex] = s[i];
            }
            else
            {
                if( sTable[sIndex] != t[i] || tTable[tIndex] != s[i] )
                {
                    return false;
                }
            }
        }
        return true;
    }
};
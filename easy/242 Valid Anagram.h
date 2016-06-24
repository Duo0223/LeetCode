class Solution {
public:
    bool isAnagram(string s, string t)
    {
        if( s.length() != t.length() )
            return false;
        
        int tableS[26] = { 0 };
        int tableT[26] = { 0 };
        
        for( int i = 0 ; i < s.length() ; ++i )
        {
            ++tableS[ s[i] - 'a' ];
            ++tableT[ t[i] - 'a' ];
        }
        
        for( int i = 0 ; i < s.length() ; ++i )
        {
            if( tableS[ s[i] - 'a' ] != tableT[ s[i] - 'a' ] )
                return false;
        }
        
        return true;
    }
};
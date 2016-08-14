class Solution {
public:
    bool wordPattern(string pattern, string str) 
    {
        istringstream inStr(str);
        vector<string> vecString;
         copy( istream_iterator<string>(inStr), istream_iterator<string>(), back_inserter(vecString) );
         
        string* hashTable[26] = { NULL };
        set< string > mappedStrings;
        
        if( pattern.length() != vecString.size() ) return false;
        
         
        for( int i = 0 ; i < pattern.length() ; ++i )
        {
            const int hashIndex = ( pattern[ i ] - 'a' );
            if( hashTable[ hashIndex ] == NULL )
            {
                hashTable[ hashIndex ] = &vecString[ i ];
                if( mappedStrings.find( vecString[ i ] ) != mappedStrings.end() )
                {
                    return false;
                }
                mappedStrings.insert(  vecString[ i ] );
            }
            else
            {
                if( hashTable[ hashIndex ]->compare( vecString[ i ] ) != 0 )
                {
                    return false;
                }
            }
        }
        
        return true;
    }
};
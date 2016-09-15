class Solution {
public:
    string convert(string s, int numRows)
    {
        const int len = (int)s.length();
        int rowLen = (len / numRows ) + 2;
        rowLen = rowLen<<1;
        int nowRow = 0;
        int direct = (numRows == 1) ? 0 : 1;
        
        char **charMap = new char* [ numRows ];
        for( int i = 0 ; i < numRows ; ++i )
        {
            charMap[ i ] = new char[ rowLen ];
            memset(charMap[i], '\0' , rowLen * sizeof(char));
        }
        
        int *rowIndex = new int[ numRows ];
        memset( rowIndex , 0 , sizeof(int) * numRows );
        
        for( int i = 0 ; i < len ; ++i )
        {
            charMap[ nowRow ][ rowIndex[ nowRow ] ] = s[ i ];
            
            ++rowIndex[ nowRow ];
            nowRow += direct;
            if( nowRow == numRows - 1 )
            {
                direct = -1;
                if( numRows == 1 )
                {
                    nowRow = 0;
                    direct = 0;
                }
            }
            else if( nowRow == 0 )
            {
                direct = 1;
                if( numRows == 1 )
                {
                    nowRow = 0;
                    direct = 0;
                }
            }
        }
        
        string ret;
        for( int i = 0 ; i < numRows ; ++i )
        {
            string str( charMap[i] );
            ret += str;
        }
        
        for( int i = 0 ; i < numRows ; ++i )
            delete [] charMap[i];
        delete [] charMap;
        delete [] rowIndex;
        return ret;
    }
};

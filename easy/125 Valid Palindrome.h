class Solution {
public:
    bool isPalindrome(string s) 
    {
        int *newStr = new int[ s.length() ];
        int count = 0 , i , j;
        const char base[2] = {'a' , 'A'};
        for( i = 0 ; i < s.length() ; ++i )
        {
            int type = -1;
            if( s[i] >= 'a' && s[i] <= 'z' )  type = 0;
            else if( s[i] >= 'A' && s[i] <= 'Z' )  type = 1;
            else if( s[i] >= '0' && s[i] <= '9' )  type = 2;
            
            if(  type == 0 || type == 1 )    newStr[count] = s[i] - base[type];
            if(  type == 2 )                 newStr[count] = (int)s[i];
            if(  type >= 0 )                 ++count;
            
        }
        i = 0;
        j = count-1;
        while( i < j )
        {
            if( newStr[i] != newStr[j] )    return false;
            ++i;
            --j;
        }
        return true;
    }
};
class Solution {
public:
    string convertToTitle(int n)
    {
        string decodeStr = "";
        while( n )
        {
            int r = n % 26;
            n /= 26;
            if( r == 0)
            {
                decodeStr += 'Z';
                --n;
            }
            else
            {
                decodeStr += ('A' + r - 1);
            }
        }
        
        int i = 0;
        int j = (int)decodeStr.length() - 1;
        while ( i < j)
        {
            char tmp = decodeStr[i];
            decodeStr[i] = decodeStr[j];
            decodeStr[j] = tmp;
            ++i;
            --j;
        }
        return decodeStr;
    }
};
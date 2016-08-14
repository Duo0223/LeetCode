class Solution {
public:
    bool isValid(string s)
    {
        stack<char> parsing;
        for( int i = 0 ; i < s.length() ; ++i )
        {
            char nowChar = s[i];
            switch( nowChar )
            {
                case ')':
                    if( parsing.empty() || parsing.top() != '(' )
                        return false;
                    parsing.pop();
                    break;
                case ']':
                    if( parsing.empty() || parsing.top() != '[' )
                        return false;
                    parsing.pop();
                    break;
                case '}':
                    if( parsing.empty() || parsing.top() != '{' )
                        return false;
                    parsing.pop();
                    break;
                default:
                    parsing.push( nowChar );
                    break;
            }
        }
        return parsing.empty();
    }
};
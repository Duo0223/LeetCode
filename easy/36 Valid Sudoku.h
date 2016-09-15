class Solution
{
public:
    bool isValidSudoku(vector<vector<char>>& board)
    {
        int mapping[10];
        if( board.size() != 9 || board[0].size() != 9 )
            return false;
        
        for( int i = 0 ; i < 9 ; ++i)
        {
            memset( mapping , 0 , sizeof( mapping ) );
            for( int j = 0 ; j < 9 ; ++j)
            {
                if( board[i][j] == '.' )
                    continue;
                if( board[i][j] < '0' || board[i][j] > '9')
                    return false;
                int num = board[i][j] - '0';
                if( mapping[num] )
                    return false;
                mapping[num] = 1;
            }
        }
        for( int j = 0 ; j < 9 ; ++j)
        {
            memset( mapping , 0 , sizeof( mapping ) );
            for( int i = 0 ; i < 9 ; ++i)
            {
                if( board[i][j] == '.' )
                    continue;
                int num = board[i][j] - '0';
                if( mapping[num] )
                    return false;
                mapping[num] = 1;
            }
        }
        for(int i = 0 ; i < 9 ; i += 3 )
        {
            for( int j = 0 ; j < 9 ; j += 3)
            {
                memset( mapping , 0 , sizeof( mapping ) );
                for( int k = i ; k < i+3 ; ++k )
                {
                    for(int l = j ; l < j+3 ; ++l )
                    {
                        if( board[k][l] == '.' )
                            continue;
                        int num = board[k][l] - '0';
                        if( mapping[num] )
                            return false;
                        mapping[num] = 1;
                    }
                }
            }
        }
        return true;
    }
};
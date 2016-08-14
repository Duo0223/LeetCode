class Solution {
public:
    vector<int> getRow(int rowIndex) 
    {
        vector<int> curr( rowIndex + 1 , 1 );
        vector<int> prev( rowIndex + 1 , 1 );
        
        for( int i = 2 ; i <= rowIndex ; ++i )
        {
            for( int j = 1 ; j < i ; ++j )
            {
                curr[j] = prev[j-1] + prev[j];
            }
            curr[i] = 1;
            prev = curr;
        }
        return curr;
    }
};
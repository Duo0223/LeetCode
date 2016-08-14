class Solution {
public:
    vector<vector<int>> generate(int numRows)
    {
        static vector< vector< int > > Pascal;
        static bool init = false;
        static int  now = 1;
        vector< vector < int > > ret;
        
        if( numRows == 0 )
            return ret;
        
        const int targetsRow = numRows - 1;
        
        if( init == false )
        {
            vector<int> tmp;
            tmp.push_back( 1 );
            Pascal.push_back( tmp );
            
            tmp.push_back( 1 );
            Pascal.push_back( tmp );
            
            init = true;
        }
        
        for( int i = now ; i < targetsRow ; ++i )
        {
            vector<int> upLevel = Pascal.at( i );
            vector<int> tmp;
            
            tmp.push_back( 1 );
            
            for( int j = 1 ; j < upLevel.size() ; ++j  )
                tmp.push_back( upLevel.at( j-1 ) + upLevel.at( j ) );
            
            tmp.push_back( 1 );
            
            Pascal.push_back( tmp );
        }
        if( targetsRow > now )
            now = targetsRow;
        
        ret.reserve( numRows );
        copy( Pascal.begin() , Pascal.begin() + numRows , back_inserter(ret) );
        
        return ret;
        
    }
};
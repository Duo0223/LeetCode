class Solution {
public:
    bool isHappy(int n) 
	{
		map< int , int > history;
		char numStr[ 16 ];
		while( 1 )
		{
			unsigned int value = 0;
			sprintf( numStr , "%d" , n );
			
			for( int i = 0 ; i < 16 && numStr[i] ; ++i )
				value += (numStr[i]-'0')*(numStr[i]-'0');
			
			if( value == 1 )
				return true;
			else
			{
				map<int , int>::iterator itr = history.find( value );
				if( itr != history.end() )
					break;
				else
					history.insert( pair<int,int>( value,1 ) );
			}
			n = value;
		}
		return false;
    }
};
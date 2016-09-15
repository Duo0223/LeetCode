class Solution 
{
public:
	bool containsNearbyDuplicate(vector<int>& nums, int k)
	{
		unordered_map< int , int > table;
		unordered_map< int , int >::iterator mapItr;
		
		for( int i = 0 ;  i < nums.size() ; ++i )
		{
			mapItr = table.find( nums[i] );
			if( mapItr == table.end() )
			{
				table.insert( pair< int , int >( nums[i] , i ) );
			}
			else
			{
				if( ( i - mapItr->second ) <= k )	
					return true;
				else
					mapItr->second = i;
			}
		}
		return false;
	}

};
class Solution {
public:
    void moveZeroes(vector<int>& nums) 
	{
		int count = 0;
		vector<int>::iterator itr;
		for( itr = nums.begin() ; itr != nums.end() ; ++itr  )
		{
			if( (*itr) == 0 )
			{
				nums.erase( itr );
				--itr;
				++count;
			}
		}
		
		for( int i = 0 ; i < count ; ++i )
		{
			nums.push_back( 0 );
		}
    }
};
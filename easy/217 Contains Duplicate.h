class Solution {
public:
    bool containsDuplicate(vector<int>& nums) 
	{	
		map<int , int> countMap;
		for( int i = 0 ; i < nums.size() ; ++i )
		{
			map<int , int>::iterator itr = countMap.find( nums[i] );
			if( itr != countMap.end() )
				return true;
			
			countMap.insert( pair<int , int>( nums[i] , 1 ) );
		}
        return false;
    }
};
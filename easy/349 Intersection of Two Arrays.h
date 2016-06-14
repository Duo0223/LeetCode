class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) 
	{
		sort( nums1.begin() , nums1.end() );
		sort( nums2.begin() , nums2.end() );
		
		vector<int> ret;
		ret.clear();
		
		int head1 = 0;
		int head2 = 0;
		while(1)
		{
			// parsing over
			if( head2 >= nums2.size() || head1 >= nums1.size() )
			{
				break;
			}
			
			int tmp1 = nums1[ head1 ];
			int tmp2 = nums2[ head2 ];
			
			// move head1
			if( tmp1 < tmp2 )
			{
				++head1;
			}
			
			// move head2
			if( tmp1 > tmp2 )
			{
				++head2;
			}
			
			// move together
			if( tmp1 == tmp2 )
			{
				ret.push_back( tmp1 );
				while( head1 < nums1.size() && nums1[ head1 ] == tmp1 )
					++head1;
				
				while( head2 < nums2.size() && nums2[ head2 ] == tmp2 )
					++head2;
				
			}
		}
		return ret;
    }
};
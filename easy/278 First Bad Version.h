// Forward declaration of isBadVersion API.
bool isBadVersion(int version);

class Solution {
public:
    int firstBadVersion(int n) 
	{
		if( isBadVersion( 1 ) )
			return 1;
		
		unsigned int head = 1;
		unsigned int end = (unsigned int)n;
		
		while( 1 )
		{
			unsigned int mid = ( head + end )>>1;
			bool isBadMid = isBadVersion( (int)mid );
			if( isBadMid )
			{
				// find the first bad => mid
				if( !isBadVersion( (int)mid - 1 ) )
				{
					return (int)mid;
				}
				else
				{
					end = mid - 1;
				}
			}
			else
			{
				head = mid + 1;
			}
		}
    }
};
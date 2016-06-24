class Solution {
public:

	bool checkFunc( char nowChar )
	{
		const char vowels[10] = {'a' , 'e' , 'i' , 'o' , 'u' ,
								 'A' , 'E' , 'I' , 'O' , 'U' };
		for( int i = 0 ; i < 10 ; ++i )
		{
			if(nowChar == vowels[i])
				return true;
		}
		return false;
	}
	
    string reverseVowels(string s) 
	{
		string ret = s;
		int head = 0;
		int end = ret.length() - 1;
		while( 1 )
		{
			if( head >= end )
				break;
			
			bool IsHead = checkFunc( ret[ head ] );
			char IsEnd = checkFunc( ret[ end ] );
			
			if( IsHead && IsEnd )
			{
				char tmp = ret[head];
				ret[head] = ret[end];
				ret[end] = tmp;
				++head;
				--end;
			}
			
			// moving head			
			if( ! IsHead )
				++head;
			
			// moving end
			if( ! IsEnd )
				--end;
					
		}
		return ret;
    }
};
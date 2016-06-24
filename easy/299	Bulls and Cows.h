class Solution {
public:
    string getHint(string secret, string guess) 
	{
		int lengthStr = secret.length();
		
        vector< int > maskA;
        vector< int > maskB;
        maskA.clear();
        maskB.clear();
        maskA.resize( lengthStr , 0 );
        maskB.resize( lengthStr , 0 );
        
        int countA = 0;
		int countB = 0;
		
		// find A
        for( int i = 0 ; i < lengthStr ; ++i )
		{
			if( secret[i] == guess[i] )
			{
				++countA;
				maskA[i] = 1;
				maskB[i] = 1;
			}
		}
			
		// find B
		for( int i = 0 ; i < lengthStr ; ++i )
		{
			if( maskA[i] == 0 )
			{
				for( int j = 0 ; j < lengthStr ; ++j )
				{
					if( maskB[j] == 0 && secret[i] == guess[j] )
					{
						++countB;
						maskA[i] = 1;
						maskB[j] = 1;
                        break;
					}
				}
			}
		}
		
        char ans[10];
        sprintf( ans , "%dA%dB" , countA , countB );
        string ret( ans );
		return ret;
    }
};
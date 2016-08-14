class Solution {
public:
    int maxProfit(vector<int>& prices) 
	{
		if( prices.size() < 2 ) 
			return 0;
		
		int maxEarn = 0;
		int low = prices[0];
		int max = -1;
		for( int i = 1 ; i < prices.size() ; ++i )
		{
			int cur = prices[i];
			int pre = prices[i-1];
			int earn = cur - pre;
			
			maxEarn = std::max( earn , maxEarn );
			maxEarn = std::max( maxEarn , cur - low );

			
			low = std::min( low , pre );
			max = std::max( max , cur );
		}
		return maxEarn;
    }
};
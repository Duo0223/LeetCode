class NumArray {
	
private:
	vector<int> mSumVector;
public:
    NumArray(vector<int> &nums) 
	{
		mSumVector.clear();
		if( nums.size() > 0 )
		{
			mSumVector.push_back( nums[0] );
			for( int i = 1 ; i < nums.size() ; ++i )
			{
				mSumVector.push_back( nums[i] + mSumVector[i-1] );
			}
		}
    }

    int sumRange(int i, int j) 
	{
		if( mSumVector.size() > 0 )
		{
			if( i == 0 )
				return mSumVector[j];
			
			return mSumVector[j] - mSumVector[i-1];
		}
		else
		{
			return 0;
		}
    }
};
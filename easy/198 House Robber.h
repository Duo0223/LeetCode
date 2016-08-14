class Solution {
public:
    int rob(vector<int>& nums) 
    {
        const int numSize = nums.size();
        if( numSize == 0 )  return 0;
        if( numSize == 1 )  return nums[0];
        
        vector<int> maxVec( numSize );
        maxVec[0] = nums[0];
        maxVec[1] = max( nums[0] , nums[1] );
        
        for( int i = 2 ; i < numSize ; ++i )
            maxVec[ i ] = max( maxVec[ i-2 ] + nums[ i ] , maxVec[ i-1 ] );
        
        return maxVec[ numSize - 1 ];
    }
};
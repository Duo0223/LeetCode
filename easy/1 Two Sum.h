class Solution
{
public:
    vector<int> twoSum(vector<int>& nums, int target)
    {
        vector<int> ret;
        unordered_map<int , int> table;
        unordered_map<int , int>::iterator itr;
        
        const int size = nums.size();
        for( int i = 0 ; i < size ; ++i )
        {
            table[ nums[ i ] ] = i;
        }
        
        for( int i = 0 ; i < size ; ++i )
        {
            int otherValue = target - nums[i];
            itr = table.find( otherValue );
            if( itr != table.end() && itr->second != i )
            {
                ret.push_back( i );
                ret.push_back( itr->second );
                break;
            }
        }
        return ret;
    }
};
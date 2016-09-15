class Solution
{
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n)
    {
        if( !nums2.size() ) return;
        
        vector<int> mergedVec( m + n );
        int i = 0 , j = 0 , nowIndex = 0;
        while ( i != m && j != n )
        {
            if( nums1[i] < nums2[j] )
            {
                mergedVec[nowIndex] = nums1[i];
                ++i;
            }
            else
            {
                mergedVec[nowIndex] = nums2[j];
                ++j;
            }
            ++nowIndex;
        }
        if( i != m )
            std::copy( nums1.begin() + i , nums1.begin() + m , mergedVec.begin() + nowIndex );
        if( j != n )
            std::copy( nums2.begin() + j , nums2.begin() + n , mergedVec.begin() + nowIndex );
        
        std::move( mergedVec.begin() , mergedVec.end() , nums1.begin() );
    }
};
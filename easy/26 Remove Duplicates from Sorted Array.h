class Solution {
public:
    int removeDuplicates(vector<int>& nums)
    {
        vector<int>::iterator itr =  std::unique( nums.begin() , nums.end() );
        int dis = std::distance( nums.begin() , itr );
        return dis;
    }
};
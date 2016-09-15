class Solution {
public:
    void rotate(vector<int>& nums, int k) 
    {
        int n = nums.size();
        k = k % n;
        
        vector<int> tmp(k , 0);
        int offset = n - k;
        copy( nums.begin() + offset , nums.end() , tmp.begin() );
        copy( nums.begin() , nums.begin() + offset , nums.begin() + k);
        copy( tmp.begin() , tmp.end() , nums.begin() );
    }
};
class Solution {
public:
    string longestCommonPrefix(vector<string> &strs)
    {
        string prefix = "";
        if( !strs.size() ) return prefix;
        int j = 0;
        while(1)
        {
            if( j == (int)strs[0].size()) break;
            char p = strs[0][j];
            int i = 1;
            for(  ; i < (int)strs.size(); ++i)
            {
                if( j == (int)strs[i].size() ) break;
                if( p != strs[i][j] )
                    break;
            }
            if(i != (int)strs.size())
                break;
            prefix.append(1,p);
            j++;
        }  
        return prefix;  
    }  
};

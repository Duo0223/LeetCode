class Solution {
public:
    int lengthOfLastWord(string s) 
    {
        s = "1" + s;
        vector<string> tokens;
        istringstream iss(s);
        copy(istream_iterator<string>(iss),
            istream_iterator<string>(),
            back_inserter(tokens));
            
        if( tokens.size() == 1 )    
            return tokens[0].size() - 1;
        
        return tokens[ tokens.size() - 1 ].size();
        
    }
};
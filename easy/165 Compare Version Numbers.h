class Solution {
public:
    int compareVersion(string version1, string version2)
    {
        istringstream v1(version1+".");
        istringstream v2(version2+'.');
        char dot = '.';
        int val1 = 0;
        int val2 = 0;
        while (1)
        {
            void *p1 = ( v1 >> val1 >> dot );
            void *p2 = ( v2 >> val2 >> dot );
            
            if ( !p1 && !p2 )       return 0;
            if ( !p1 )              val1 = 0;
            if ( !p2 )              val2 = 0;
            if ( val1 > val2 )      return 1;
            else if ( val1 < val2 ) return -1;
        }
    }
};
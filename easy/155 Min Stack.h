class MinStack {
    
    vector<int> mStack;
    int         mMin;
    int         mTop;
public:
    /** initialize your data structure here. */
    MinStack()
    {
        mMin = INT_MAX;
        mStack.clear();
        mTop = -1;
    }
    
    void push(int x)
    {
        if( x < mMin ) mMin = x;
        if( ( mTop + 1 ) == mStack.size() )
            mStack.push_back( x );
        else
            mStack[ mTop + 1 ] = x;
        ++mTop;
    }
    
    void pop()
    {
        if( mStack[ mTop ] == mMin )
        {
            int tmpMin = ( mTop - 1 < 0 ) ? INT_MAX : mStack[ mTop - 1 ];
            for( int i = mTop - 2 ; i >= 0 ; --i )
            {
                if( tmpMin > mStack[ i ] )
                    tmpMin = mStack[ i ];
            }
            mMin = tmpMin;
        }
        --mTop;
    }
    
    int top()
    {
        return mStack[ mTop ];
    }
    
    int getMin()
    {
        return mMin;
    }
};

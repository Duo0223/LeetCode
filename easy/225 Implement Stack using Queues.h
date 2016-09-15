class Stack 
{
protected:

    queue<int>  mQueue[2];
    int         mIndex;
    int         mTop;
    
public:
    Stack()
    {
        mIndex = 0;
    }
    // Push element x onto stack.
    void push(int x) 
    {
        mTop = x;
        mQueue[ mIndex ].push( x );
    }

    // Removes the element on top of the stack.
    void pop() 
    {
        int otherIndex = (mIndex + 1)%2;
        while( mQueue[ mIndex ].size() > 1 )
        {
            mQueue[ otherIndex ].push( mQueue[ mIndex ].front() );
            mTop = mQueue[ mIndex ].front();
            mQueue[ mIndex ].pop();
        }
        mQueue[ mIndex ].pop();
        mIndex = otherIndex;
    }

    // Get the top element.
    int top() 
    {
        return mTop;    
    }

    // Return whether the stack is empty.
    bool empty() 
    {
        return ( mQueue[0].empty() && mQueue[1].empty() );
    }
};
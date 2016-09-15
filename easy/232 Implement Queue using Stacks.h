class Queue {
    
    stack< int > m_Front;
    stack< int > m_Back;
public:
    // Push element x to the back of queue.
    void push(int x)
    {
        m_Back.push( x );
    }
    
    // Removes the element from in front of queue.
    void pop(void)
    {
        update();
        m_Front.pop();
    }
    
    // Get the front element.
    int peek(void)
    {
        update();
        return m_Front.top();
    }
    
    // Return whether the queue is empty.
    bool empty(void)
    {
        return ( m_Front.empty() && m_Back.empty() );
        
    }
private:
    void update( void )
    {
        if( m_Front.empty() )
        {
            while( !m_Back.empty() )
            {
                m_Front.push( m_Back.top() );
                m_Back.pop();
            }
        }
    }
};
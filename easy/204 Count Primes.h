class Solution {
public:
    int countPrimes(int n)
    {
        
        bool* isPrime = new bool[ n ];
        memset( isPrime , true , sizeof( bool ) * n  );
        
        // Loop's ending condition is i * i < n instead of i < sqrt(n)
        // to avoid repeatedly calling an expensive function sqrt().
        for (int i = 2; i * i < n; ++i)
        {
            if (!isPrime[i]) continue;
            for (int j = i * i; j < n; j += i)
            {
                isPrime[j] = false;
            }
        }
        int count = 0;
        for (int i = 2; i < n; ++i)
        {
            if (isPrime[i]) ++count;
        }
        
        delete [] isPrime;
        return count;
    }
};
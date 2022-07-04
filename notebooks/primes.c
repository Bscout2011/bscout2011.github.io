#include <stdio.h>

#define N 10000

void main()
{
    int primes[N] = {0};
    primes[0] = 3;

    int n = 1;
    int max = primes[n-1];

    for(n=0; n < N-1; ++n) {
        int num = primes[n] + 2;
        for(int i=0; i <= n; ++i) {
            
        }
    }
    
}
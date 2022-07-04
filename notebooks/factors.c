#include <stdio.h>

int isprime(long int x) {
    for(int i = 2; i <= x/2; ++i)
    {
        if (x % i == 0) return 0;
    }
    return 1;
}

int main()
{
    long num = 600851475143;
    long largest = 0;
    long i = 2;

    printf("Largest Prime factor of %ld", num);
    while (num > 1)
    {
        printf("Finding factor of %ld\n", num);
        // printf("Searching from 2 to %ld\n", num/2);
        for(i = 2; i <= num; ++i) {
            if (num % i == 0)
            {
                printf("%ld, ", i);
                num = num / i;
                if (i > largest)
                    largest = i;
                break;
            }
            if (i % 100000 == 0)
                printf("Searching past %ld", i);
        }
    }
    
    return (int)(largest);
}
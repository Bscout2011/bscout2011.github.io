#include <stdio.h>

// Largest palindrome that is product of three digit numbers
int isPalindrome(int x)
{
    if(x < 0 || (x % 10 == 0 && x != 0)) {
        return 0;
    }
    int reverse = 0;
    while (x > reverse) {
        reverse = reverse * 10 + x % 10;
        x /= 10;
    }
    return x == reverse || x == reverse/10;
}

void main()
{
    // Largest implies starting from 1000 x 1000 and working backwards.
    int i = 999;
    int j = 999;
    int largest = 0; 
    while (i >= 100){

        for (j=999; j >= 100; --j)
        {
            int prod = i * j;
            if(isPalindrome(prod) && prod > largest)
            {
                largest = prod;
                printf("%d x %d = %d\n", i, j, prod);
            }
        }
        --i;
    }
   
    printf("%d\n", largest);
}
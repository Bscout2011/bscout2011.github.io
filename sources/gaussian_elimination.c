#include <math.h>
#include "nrutil.h"

#define SWAP(a,b) {temp=(a);(a)=(b);(b)=temp;}

void gaussj(float **a, int n, float **b, int m)
{
    int *indxc, *indxr, *ipiv;
    int i, icol, irow, j, k, l, ll;
    float big, dum, pivinv, temp;

    indxc = ivector(1, n);
    indxr = ivector(1, n);
    ipiv = ivector(1, n);
    for (j=1; j<= n; ++j) ipiv[j] = 0;
    for (i=1; i<=n; ++i) {
        big = 0.0;
        for (j=1; j<=n; ++j) {
            if (ipiv[j] != 1) {  // search for a pivot
                for (k=1; k<=n; ++k) {
                    if (ipiv[k] == 0) {
                        if (fabs(a[j][k]) >= big) {
                            big = fabs(a[j][k]);
                            irow=j;
                            icol=k;
                        }
                    }
                }
            }
        }
        ++(ipiv[icol]);
    }
}
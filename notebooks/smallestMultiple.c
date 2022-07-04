#include <stdio.h>
#include <limits.h>


#define N 20

int equal(int seq[N])
{
    for(int i = 2; i < N; ++i) {
        if(seq[i-1] != seq[i])
            return 0;
    }
    return 1;
}

int minIdx(int seq[N])
{
    int min = INT_MAX;
    int minidx = -1;
    for(int i=1; i < N; ++i) {
        if (seq[i] <= min) {
            min = seq[i];
            minidx = i;
        }
    }
    return minidx;
}

void printSeq(int seq[N]) {
    for(int i=0; i<N; ++i)
        printf("%d  ", seq[i]);
    printf("\n");
}

void main()
{
    int seq[N] = {0};
    int running[N] = {0};
    int idx = -1;

    for (int i=1; i < N; ++i) {
        seq[i] = i+1;
        running[i] = i+1;
    }

    while(!equal(running)) {
        idx = minIdx(running);
        running[idx] += seq[idx];
       
    }
    printSeq(running);

    printf("%d \n", running[1]);
}
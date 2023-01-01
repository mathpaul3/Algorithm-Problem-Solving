#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main() {
    int N, M, X, Y, i;
    scanf("%d %d", &N, &M);
    int *ball = (int *)malloc(sizeof(int)*N);

    for (i=0; i<N; i++)
        ball[i] = i+1;
    
    for (i=0; i<M; i++)
    {
        scanf("%d %d", &X, &Y);
        ball[X-1] = Y;
    }

    for (i=0; i<N; i++)
        printf("%d\n", ball[i]);
    
    return 0;
}
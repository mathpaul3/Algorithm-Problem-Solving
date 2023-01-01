#include <stdio.h>
#include <stdlib.h>

char transform(char c)
{
    return ((int)c < 91) ? (char)((int)c + 32) : (char)((int)c - 32);
}

int main()
{
    int N, K, i;
    char *T;
    scanf("%d %d", &N, &K);
    T = (char *)malloc(sizeof(char) * N);
    scanf("%s", T);

    for (i = 0; i < N; i++)
    {
        printf("%c", (i > K - 2) ? transform(T[i]) : T[i]);
    }

    free(T);

    return 0;
}
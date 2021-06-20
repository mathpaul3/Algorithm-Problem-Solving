#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>

int main()
{
    int T, N, L, maxN;
    char S[20] = "", max[20] = "";
    scanf("%d", &T);
    for (maxN = 0; T > 0; --T)
    {
        scanf("%d", &N);
        for (; N > 0; --N)
        {
            scanf("%s %d", S, &L);
            if (L > maxN)
            {
                maxN = L;
                strcpy(max, S);
            }
        }
        printf("%s\n", max);
    }
}
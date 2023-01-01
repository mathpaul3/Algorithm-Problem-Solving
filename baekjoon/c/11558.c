#include <stdio.h>

int main()
{
    int T, N, i, j, K = 0;
    int arr[10100] = {
        0,
    };
    scanf("%d", &T);
    for (; T > 0; --T)
    {
        K = 0;
        scanf("%d", &N);
        for (i = 1; i <= N; ++i)
        {
            scanf("%d", &arr[i]);
        }
        for (i = 1, j = 0; j < N; ++j)
        {
            ++K;
            if (arr[i] == N)
                break;
            i = arr[i];
        }
        printf("%d\n", j == N ? 0 : K);
    }
}
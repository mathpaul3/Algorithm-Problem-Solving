#include <stdio.h>

int main() {
    int N, M, i, temp, cnt=0;
    int box[2000] = {0, };
    scanf("%d %d", &N, &M);

    for (i=0; i<N; i++)
    {
        scanf("%d", &temp);
        box[temp - 1]++;
    }
    for (i=0; i<M; i++)
    {
        scanf("%d", &temp);
        cnt += box[temp-1];
        box[temp-1] = 0;
    }
    printf("%d", cnt);
    return 0;
}
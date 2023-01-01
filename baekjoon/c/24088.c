#include <stdio.h>

int main() {
    int N, K, i, cntR=0;
    char temp;
    scanf("%d %d", &N, &K);
    for (i=0; i<N; i++)
    {
        scanf("%c", &temp);
        if (temp == 'R') cntR++;
    }
    printf("%c", cntR == K ? 'W' : 'R');
    return 0;
}
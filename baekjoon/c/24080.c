#include <stdio.h>
#include <stdlib.h>

int main() {
    int N, i, cnt=0, check[5] = {0, };
    char *S = (char *)malloc(sizeof(char) * N);
    scanf("%d %s", &N, S);
    for (i=0; i<N; i++)
    {
        if (S[i] == 'A') check[0] = 1;
        else if (S[i] == 'B') check[1] = 1;
        else if (S[i] == 'C') check[2] = 1;
        else if (S[i] == 'D') check[3] = 1;
        else if (S[i] == 'E') check[4] = 1;
    }
    for (i=0; i<5; i++)
    {
        if (check[i] == 1) cnt++;
    }
    printf("%s", cnt>2 ? "Yes" : "No");
    return 0;
}
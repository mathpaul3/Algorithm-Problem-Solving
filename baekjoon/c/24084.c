#include <stdio.h>
#include <stdlib.h>

int main() {
    int N, i;
    scanf("%d", &N);
    char *S = (char *)malloc(sizeof(char)*(N+1));
    scanf("%s", S);

    for(i=0; i<N-1; i++) {
        if (S[i+1] == 'J')
            printf("%c\n", S[i]);
    }
    return 0;
}
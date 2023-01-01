#include <stdio.h>

int main() {
    int N, A[2020] = {0, };
    int i, temp, min=1000, mini;
    scanf("%d", &N);
    for (i=0; i<N; i++)
    {
        scanf("%d", &temp);
        A[temp]++;
    }
    
    for (i=0; i<2020; i++)
    {
        if (A[i] != 0 && A[i]<min) {
            min = A[i];
            mini = i;
        }
    }
    printf("%d", mini);
    return 0;
}
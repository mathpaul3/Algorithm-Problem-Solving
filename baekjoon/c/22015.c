#include <stdio.h>

int main()
{
    int A, B, C, m = 0;
    scanf("%d %d %d", &A, &B, &C);

    if (m < A)
        m = A;
    if (m < B)
        m = B;
    if (m < C)
        m = C;
    printf("%d", m * 3 - (A + B + C));
    return 0;
}
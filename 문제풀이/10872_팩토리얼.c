#include <stdio.h>

int factorial(int N, long long int num)
{
    if (N == 0)
        return 1;
    num = num * N * factorial(--N, num);
    return num;
};

int main()
{
    int N;
    scanf("%d", &N);
    printf("%lld", factorial(N, 1));
}
#include <stdio.h>

void hanoi(int N, int ans)
{

    printf("%d %d");
    hanoi(N, --ans);
};

int main()
{
    int N;
    long long int ans;
    scanf("%d", &N);
    ans = (1 << N) - 1;
    printf("%lld\n", ans);
    for (; ans > 0; --ans)
    {
        printf("%d %d\n", 1, ans % 2 == 0 ? 2 : 3);
    }
}

// 13
// 12 13 23
// 13 12 32 13 21 23 13
// 12 13 23 12 31 32 12 13 23 21 31 23 12 13 23
// 13 12 32 13 21 23 13 12 32 31 21 32 13 12 32 13 21 23 13 21 32 31 21  23 13 12 32 13 21 23 13
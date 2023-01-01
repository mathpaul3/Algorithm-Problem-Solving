#include <stdio.h>

int main() {
    int S, A, B;
    int cnt, cost=250;
    scanf("%d %d %d", &S, &A, &B);

    if (A>S) {
        printf("%d", cost);
        return 0;
    }
    cnt = (S-A)/B;
    if ((S-A) % B != 0) cnt++;
    cost += cnt*100;
    printf("%d", cost);
    return 0;
}
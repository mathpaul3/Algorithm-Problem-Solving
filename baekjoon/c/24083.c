#include <stdio.h>

int main() {
    int A, B;
    scanf("%d %d", &A, &B);
    printf("%d", (A+B)%12 == 0 ? 12 : (A+B)%12);
    return 0;
}
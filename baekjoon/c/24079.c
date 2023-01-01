#include <stdio.h>

int main() {
    int X, Y, Z;
    scanf("%d %d %d", &X, &Y, &Z);
    printf("%d", X+Y>Z ? 0 : 1);
    return 0;
}
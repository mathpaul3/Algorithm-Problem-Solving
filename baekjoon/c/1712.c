#include <stdio.h>
int main(){
	int A, B, C;
	scanf("%d %d %d", &A, &B, &C);
	printf("%d", B >= C ? -1 : A / (C - B) + 1);
}

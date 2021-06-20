#include <stdio.h>

int main() {
	int N, j, Now, now;
	scanf("%d", &N);
	Now = N*2-1;
	for(int i = 1; i <= N; ++i) {
		j = i-1;
		while (j) {
			printf(" ");
			--j;
		}
		now = Now;
		while (now) {
			printf("*");
			--now;
		}
		printf("\n");
		Now -= 2;
	}
}

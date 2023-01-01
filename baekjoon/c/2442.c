#include <stdio.h>

int main() {
	int N, j, Now = 1, now;
	scanf("%d", &N);
	for(int i = N; i > 0; --i) {
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
		Now += 2;
	}
}

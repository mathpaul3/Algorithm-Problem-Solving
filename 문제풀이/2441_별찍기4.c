#include <stdio.h>
int main() {
	int N, i, j;
	scanf("%d", &N);
	i = N;
	while(N) {
		j = i;
		while (j) {
			if (j-N>0) {
				printf(" ");
			} else {
				printf("*");
			}
			--j; 
		}
		--N;
		printf("\n");
	}
}

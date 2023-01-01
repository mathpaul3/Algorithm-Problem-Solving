#include <stdio.h>
int main() {
	int N;
	scanf("%d", &N);
	while (N) {
		for (int i = N; i > 0; --i) {
			printf("*");
		} printf("\n");
		--N; 
	}
}

#include <stdio.h>

int main() {
	int N;
	scanf("%d", &N);
	for (int i = 2*N-1; i > 0; i--) {
		if (i >= N) {
			for (int j = 1; j <= 2*N-i; j++) printf("*");
			printf("\n");
		} else {
			for (int j = i; j > 0; j--) printf("*");
			printf("\n");
		}
	}
}

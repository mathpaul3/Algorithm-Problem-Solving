#include <stdio.h>

int main() {
	int N, a, M=0;
	double sum = 0;
	scanf("%d", &N);
	for (int i = 0; i < N; i++) {
		scanf("%d", &a);
		sum += a;
		a>M ? M=a : 0;
	}
	sum = sum/M*100/N;
	printf("%lf", sum);
}

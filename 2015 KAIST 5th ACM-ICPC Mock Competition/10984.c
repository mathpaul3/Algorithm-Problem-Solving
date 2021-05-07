#include <stdio.h>

int main() {
	int T, N, C, CSum;
	double G, GSum;
	scanf("%d", &T);
	while(T) {
		T--;
		CSum=0, GSum=0;
		scanf("%d", &N);
		while(N) {
			N--;
			scanf("%d %lf", &C, &G);
			CSum+=C;
			GSum+=G*(double)C;
		}
		printf("%d %.1f\n", CSum, GSum/(double)CSum);
	}
}

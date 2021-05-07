#include <stdio.h>

int main() {
	int T, N, i=2;
	long long an, an1, an2;
	scanf("%d", &T);
	while (T) {
		T--;
		i=2, an1=1, an2=0;
		scanf("%d", &N);
		if (N<3) {
			printf("%d\n", N-1);
			continue;
		} else {
			for (; i<N; i++) {
				an = i*(an1+an2);
				an2 = an1;
				an1 = an;
			}
			printf("%lld\n", an);
		}
	}
}

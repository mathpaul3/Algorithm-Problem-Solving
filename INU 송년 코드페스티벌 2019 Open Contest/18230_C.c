#include <stdio.h>

int main() {
	int N, A, B, C, a[2000] = {0, }, b[2000] = {0, }, sum = 0;
	scanf("%d %d %d", &N, &A, &B);
	for (int i = 0; i < A; i++) {
		scanf("%d", &a[i]);
		for (int j = 0; j < i; j++) {
			if (a[i] > a[j]) {
				C = a[i];
				a[i] = a[j];
				a[j] = C;
			}
		}
	}
	for (int i = 0; i < B; i++) {
		scanf("%d", &b[i]);
		for (int j = 0; j < i; j++) {
			if (b[i] > b[j]) {
				C = b[i];
				b[i] = b[j];
				b[j] = C;
			}
		}
	}
	int pta = 0, ptb = 0;	
	if (N % 2 == 1) {
			sum += a[0];
			--N;
			++pta;
		}
	for (; N > 0;) {
		if (b[ptb] + a[ptb] == 0) break;
		if (b[ptb] >= a[pta] + a[pta + 1]) {
			sum += b[ptb];
			++ptb;
			N -= 2;
		} else {
			sum += a[pta] + a[pta + 1];
			pta += 2;
			--N;
		}
	}
	printf("%d", sum);
}

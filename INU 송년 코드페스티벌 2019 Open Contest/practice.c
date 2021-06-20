#include <stdio.h>

int main() {
	int N, A, B, C, sum=0;
	int a[2000] = {0, }, b[2000] = {0, };
	scanf("%d %d %d", &N, &A, &B);
	for (int i = 0; i < A; i++) {
		scanf("%d", &a[i]);
		for (int j = 0; j < i; j++) {
			if (a[j] < a[i]) {
				C = a[j];
				a[j] = a[i];
				a[i] = C;
			}
		}
	}
	for (int i = 0; i < B; i++) {
		scanf("%d", &b[i]);
		for (int j = 0; j < i; j++) {
			if (b[j] < b[i]) {
				C = b[j];
				b[j] = b[i];
				b[i] = C;
			}
		}
	}
	
	
	int pta=0, ptb=0;
	
	if (N%2 == 1) {
		sum += a[pta];
		++pta;
		--N;
	}
	for (;N>0;) {
		if (a[pta]+a[pta+1] >= b[ptb]) {
			sum += a[pta]+a[pta+1];
			pta += 2;
		} else {
			sum += b[ptb];
			++ptb;
		}
		N -= 2;
		if (!a[pta] && !b[ptb]) break;
	}
	printf("%d", sum);
}

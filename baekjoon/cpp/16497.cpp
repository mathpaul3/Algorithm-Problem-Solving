#include <stdio.h>

int main() {
	int date[32] = {0, };
	int N;
	int b, r;
	int K;
	bool a = true;
	
	scanf("%d", &N);
	for (int i = 0; i < N; i++) {
		scanf("%d %d", &b, &r);
		for (int j = b, k = r; j < k; j++) {
			date[j] += 1;
		}
	}
	scanf("%d", &K);
	for (int i = 1; i < 32; i++) {
		if (date[i] > K) a = false;
	}
	printf(a ? "1" : "0");
	
}

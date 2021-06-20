#include <stdio.h>

int main() {
	int N, n, a[1000] = {0, }, big;
	double mean;
	scanf("%d", &N);
	while(N++){
		scanf("%d", &n);
		for (int i = 0; i < n; i++) {
			scanf("%d", &a[i]);
			mean += a[i];
		}
		mean /= n;
		for (int i = 0; i < n; i++) {
			mean < a[i] ? big++ : 0;
			a[i] = 0;
		}
		printf("%.3lf%%\n", (double)big/n*100);
		mean = big = 0;
		N -= 2;
	}
}
